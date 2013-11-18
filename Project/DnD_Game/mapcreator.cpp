#include "mapcreator.h"
#include "ui_mapcreator.h"
#include <QFileDialog>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <iostream>
#include <fstream>
#include <string>
#include "clicklabel.h"
#include <QMessageBox>
#include "maphelpdialog.h"
#include <QDebug>

MapCreator::MapCreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapCreator)
{
    ui->setupUi(this);
    ui->gridLayout->setSpacing(0);
    setupDefaults();
    // Connected options to click signal
    connect(ui->wallImage, SIGNAL(clicked()), this, SLOT(change_selected()));
    connect(ui->startImage, SIGNAL(clicked()), this, SLOT(change_selected()));
    connect(ui->endImage, SIGNAL(clicked()), this, SLOT(change_selected()));
    connect(ui->chestImage, SIGNAL(clicked()), this, SLOT(change_selected()));
    connect(ui->emptyImage, SIGNAL(clicked()), this, SLOT(change_selected()));
    connect(ui->ratImage, SIGNAL(clicked()), this, SLOT(change_selected()));
}

MapCreator::~MapCreator()
{
    delete ui;
}

void MapCreator::setupDefaults()
{
    height = 0;
    width = 0;
    startPos = -1;
    endPos = -1;
    // Set Wall as automatically selected
    ui->wallImage->setStyleSheet("border: 2px solid red");
    ui->startImage->setStyleSheet("border: none");
    ui->endImage->setStyleSheet("border: none");
    ui->chestImage->setStyleSheet("border: none");
    ui->emptyImage->setStyleSheet("border: none");
    ui->ratImage->setStyleSheet("border: none");
    selectType = 'W';
    ui->wValue->setValue(5);
    ui->hValue->setValue(5);
}

void MapCreator::on_actionE_xit_triggered()
{
    // If user has edited map opened
    if (!map.empty()) {
        // Display warning about unsaved map
        QMessageBox::StandardButton warn = QMessageBox::warning(this, "Save Map?", "Do you want to save the changes you have made to the current map?", QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel, QMessageBox::Yes);
        if (warn == QMessageBox::Yes) {
            if (!on_action_Save_triggered()) {
                return;
            }
            deleteMap();
            this->close();
        }
        else if (warn == QMessageBox::Cancel) {
            return;
        }
        else if (warn == QMessageBox::No) {
            deleteMap();
            this->close();
        }
    }
}

void MapCreator::on_action_Open_triggered()
{
    // If user has edited map opened
    if (!map.empty()) {
        // Display warning about unsaved map
        QMessageBox::StandardButton warn = QMessageBox::warning(this, "Save Map?", "Do you want to save the changes you have made to the current map?", QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel, QMessageBox::Yes);
        if (warn == QMessageBox::Yes) {
            if (!on_action_Save_triggered()) {
                return;
            }
            deleteMap();
            QString mapName = QFileDialog::getOpenFileName(this, tr("Open Map"), "/", tr("MAP Files (*.dcmap)"));
        }
        else if (warn == QMessageBox::Cancel) {
            return;
        }
        else if (warn == QMessageBox::No) {
            deleteMap();
            QString mapName = QFileDialog::getOpenFileName(this, tr("Open Map"), "/", tr("MAP Files (*.dcmap)"));
        }
    }
}

bool MapCreator::on_action_Save_triggered()
{
    if (validateMap()) {
        QString mapName = QFileDialog::getSaveFileName(this, tr("Save Map"), "/", tr("MAP Files (*.dcmap)"));
        std::string fileName = mapName.toStdString();
        std::ofstream f(fileName, std::ios::out);
        if (f.is_open())
        {
            f << width << std::endl << height << std::endl;

            for (int i = 0; i < height; ++i)
            {
                for (int j = 0; j < width; ++j)
                {
                    f << mapChars.at((i*width)+j) << " ";
                }
                f << std::endl;
            }
            f.close();
        }
        else
        {
            QMessageBox::StandardButton err = QMessageBox::critical(this, "Error saving map!", "ERROR: Map could not be saved.", QMessageBox::Ok);
            return false;
        }
        return true;
    }
    return false;
}

void MapCreator::on_action_New_triggered()
{
    // If user has edited map opened
    if (!map.empty()) {
        // Display warning about unsaved map
        QMessageBox::StandardButton warn = QMessageBox::warning(this, "Save Map?", "Do you want to save the changes you have made to the current map?", QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel, QMessageBox::Yes);
        if (warn == QMessageBox::Yes) {
            if (!on_action_Save_triggered()) {
                return;
            }
            deleteMap();
            setupDefaults();
        }
        else if (warn == QMessageBox::Cancel) {
            return;
        }
        else if (warn == QMessageBox::No) {
            deleteMap();
            setupDefaults();
        }
    }
}

void MapCreator::on_goButton_clicked()
{
    int w = ui->wValue->value();
    int h = ui->hValue->value();
    populateMap(w, h);
}

void MapCreator::populateMap(int w, int h)
{
    // Check for changes first
    if (h != height || w != width) {
        if (height == 0 && width == 0) {
            height = h;
            width = w;
            addCells();
        }
        // If user is trying to change the size of a map
        else {
            // Display warning before proceding
            QMessageBox::StandardButton warn = QMessageBox::warning(this, "Warning", "Changing the size of the map will reset all cells. This may result in the loss of data. Are you sure you wish to continue?", QMessageBox::Yes|QMessageBox::No, QMessageBox::No);
            if (warn == QMessageBox::Yes) {
                deleteMap();
                height = h;
                width = w;
                addCells();
            }
            else {
                // Reset values
                h = height;
                w = width;
                ui->hValue->setValue(height);
                ui->wValue->setValue(width);
            }
        }
    }
}

void MapCreator::addCells() {

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ClickLabel* cell = new ClickLabel(this);
            cell->setStyleSheet("border: 1px solid");
            cell->setScaledContents(true);
            cell->setObjectName(QString::number((i*width)+j));
            map << cell;
            mapChars << '.';
            ui->gridLayout->addWidget(cell, i, j);
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ClickLabel* currCell = map.at((i*width)+j);
            connect(map.at((i*width)+j), SIGNAL(clicked()), this, SLOT(map_label_clicked()));

            if (i == 0 || j == 0 || i == height-1 || j == width-1) {
                QPixmap img = QPixmap(":/images/wall.png");
                img = img.scaled(currCell->width(), currCell->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                currCell->setPixmap(img);
                mapChars[(i*width)+j] = '#';
            }
            else {
                QPixmap img = QPixmap(":/images/mud.png");
                img = img.scaled(currCell->width(), currCell->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                currCell->setPixmap(img);
                mapChars[(i*width)+j] = '.';
            }
        }
    }
}

void MapCreator::on_action_Help_triggered()
{
    MapHelpDialog *help = new MapHelpDialog();
    help->show();
}

void MapCreator::map_label_clicked()
{
    int index = QObject::sender()->objectName().toInt();
    if (index == 0 || index == width-1 || index == map.size()-1 || index == map.size()-width) {
        return;
    }
    // Start and End are added in a special way
    // Must make sure to only have one Start
    else if (selectType == 'S') {
        if (startPos != -1) {
            if (startPos <= width || startPos%width == 0 || (startPos+1)%width == 0 || startPos >= (map.size()-width)) {
                QPixmap img = QPixmap(":/images/wall.png");
                img = img.scaled(map.at(startPos)->width(), map.at(startPos)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                map.at(startPos)->setPixmap(img);
                mapChars[startPos] = '#';
            }
            else {
                QPixmap img = QPixmap(":/images/mud.png");
                img = img.scaled(map.at(startPos)->width(), map.at(startPos)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                map.at(startPos)->setPixmap(img);
                mapChars[startPos] = '.';
            }
        }
        QPixmap img = QPixmap(":/images/startdoor.png");
        img = img.scaled(map.at(index)->width(), map.at(index)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map.at(index)->setPixmap(img);
        mapChars[index] = 'S';
        startPos = index;
        return;
    }
    // Must make sure to only have one End
    else if (selectType == 'E') {
        if (endPos != -1) {
            if (endPos <= width || endPos%width == 0 || (endPos+1)%width == 0 == 0 || endPos >= (map.size()-width)) {
                QPixmap img = QPixmap(":/images/wall.png");
                img = img.scaled(map.at(endPos)->width(), map.at(endPos)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                map.at(endPos)->setPixmap(img);
                mapChars[endPos] = '#';
            }
            else {
                QPixmap img = QPixmap(":/images/mud.png");
                img = img.scaled(map.at(endPos)->width(), map.at(endPos)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                map.at(endPos)->setPixmap(img);
                mapChars[endPos] = '.';
            }
        }
        QPixmap img = QPixmap(":/images/enddoor.png");
        img = img.scaled(map.at(index)->width(), map.at(index)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map.at(index)->setPixmap(img);
        mapChars[index] = 'E';
        endPos = index;
        return;
    }
    // Can only add doors or walls to the edges
    else if (index <= width || index%width == 0 || (index+1)%width == 0 || index >= (map.size()-width)) {
        if (selectType == 'W') {
            // Reset Start and End locations, if replacing one
            if (startPos == index) {
                startPos = -1;
            }
            else if (endPos == index) {
                endPos = -1;
            }
            QPixmap img = QPixmap(":/images/wall.png");
            img = img.scaled(map.at(index)->width(), map.at(index)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            map.at(index)->setPixmap(img);
            mapChars[index] = '#';
        }
        return;
    }
    // Any other acceptable character can be added in the map
    else if (selectType == 'W') {
        // Reset Start and End locations, if replacing one
        if (startPos == index) {
            startPos = -1;
        }
        else if (endPos == index) {
            endPos = -1;
        }
        QPixmap img = QPixmap(":/images/wall.png");
        img = img.scaled(map.at(index)->width(), map.at(index)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map.at(index)->setPixmap(img);
        mapChars[index] = '#';
        return;
    }
    else if (selectType == '-') {
        // Reset Start and End locations, if replacing one
        if (startPos == index) {
            startPos = -1;
        }
        else if (endPos == index) {
            endPos = -1;
        }
        QPixmap img = QPixmap(":/images/mud.png");
        img = img.scaled(map.at(index)->width(), map.at(index)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map.at(index)->setPixmap(img);
        mapChars[index] = '.';
        return;
    }
    else if (selectType == 'C') {
        // Reset Start and End locations, if replacing one
        if (startPos == index) {
            startPos = -1;
        }
        else if (endPos == index) {
            endPos = -1;
        }
        QPixmap img = QPixmap(":/images/chest.png");
        img = img.scaled(map.at(index)->width(), map.at(index)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map.at(index)->setPixmap(img);
        mapChars[index] = 'C';
        return;
    }
    else if (selectType == 'M') {
        // Reset Start and End locations, if replacing one
        if (startPos == index) {
            startPos = -1;
        }
        else if (endPos == index) {
            endPos = -1;
        }
        QPixmap img = QPixmap(":/images/rat.png");
        img = img.scaled(map.at(index)->width(), map.at(index)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map.at(index)->setPixmap(img);
        mapChars[index] = 'M';
        return;
    }
}

void MapCreator::change_selected()
{
    ui->wallImage->setStyleSheet("border: none");
    ui->startImage->setStyleSheet("border: none");
    ui->endImage->setStyleSheet("border: none");
    ui->chestImage->setStyleSheet("border: none");
    ui->emptyImage->setStyleSheet("border: none");
    ui->ratImage->setStyleSheet("border: none");
    if (QObject::sender()->objectName() == ui->wallImage->objectName()) {
        ui->wallImage->setStyleSheet("border: 2px solid red");
        selectType = 'W';
    }
    else if (QObject::sender()->objectName() == ui->startImage->objectName()) {
        ui->startImage->setStyleSheet("border: 2px solid red");
        selectType = 'S';
    }
    else if (QObject::sender()->objectName() == ui->endImage->objectName()) {
        ui->endImage->setStyleSheet("border: 2px solid red");
        selectType = 'E';
    }
    else if (QObject::sender()->objectName() == ui->chestImage->objectName()) {
        ui->chestImage->setStyleSheet("border: 2px solid red");
        selectType = 'C';
    }
    else if (QObject::sender()->objectName() == ui->emptyImage->objectName()) {
        ui->emptyImage->setStyleSheet("border: 2px solid red");
        selectType = '-';
    }
    if (QObject::sender()->objectName() == ui->ratImage->objectName()) {
        ui->ratImage->setStyleSheet("border: 2px solid red");
        selectType = 'M';
    }
}

void MapCreator::deleteMap()
{
    // Remove all pointers in QList
    while (!map.isEmpty()) {
        map.removeLast();
    }
    while (!mapChars.isEmpty()) {
        mapChars.removeLast();
    }
    // Delete all cells
    while (QLayoutItem* item = ui->gridLayout->takeAt(0))
    {
        if (QWidget* widget = item->widget()) {
            ui->gridLayout->removeWidget(widget);
            delete widget;
        }
        ui->gridLayout->removeItem(item);
        delete item;
    }
}

bool MapCreator::validateMap()
{
    if (startPos == -1 || endPos == -1) {
        QMessageBox::StandardButton err = QMessageBox::critical(this, "Invalid Map!", "This map is not valid. Your map must have one (S)tart cell and one (E)nd cell.", QMessageBox::Ok);
        return false;
    }

    //Using ideas from "the right hand rule" for maze travesal this method runs through the map
    //ensuring that the exit tile is always accesible from the start tile.
    //    int index = startPos;
    //    int i, j;
    //    i = (index-j)/width;
    //    j = index - (i*width);
    //    char** visited = new char*[width];

    //    for(int c=0; c<width; c++)
    //        visited[c] = new char[height];

    //    visited[i][j] = 'v';

    //    do
    //    {
    //        //goes to the right cell if possible
    //        if (index <= width || index%width == 0 || (index+1)%width == 0 || index >= (map.size()-width)) {

    //            if((index+1)%width != 0 && (mapChars.at(index+1) == '.' || mapChars.at(index+1) == 'E') && visited[i+1][j] != 'v' && visited[i+1][j] != 'd')
    //        {
    //            i++;
    //            index = ((i+1)*width)+j;
    //            visited[i][j]='v';
    //        }

    //        //otherwise goes up 1 cell, if possible
    //        else if(j-1>=0 && (grid[i][j-1].currentState == Cell::state:: EMPTY|| grid[i][j-1].currentState ==Cell::state:: EXIT) && visited[i][j-1] != 'v' && visited[i][j-1] != 'T')
    //        {
    //            j--;
    //            visited[i][j] = 'v';
    //        }

    //        //otherwise goes left 1 cell, if possible
    //        else if(i-1>=0 && (grid[i-1][j].currentState == Cell::state:: EMPTY||grid[i-1][j].currentState ==Cell::state:: EXIT) && visited[i-1][j] != 'v' && visited[i-1][j] != 'T')
    //        {
    //            i--;
    //            visited[i][j] = 'v';
    //        }

    //        //otherwise goes down 1 cell, if possible
    //        else if(j+1<height && (grid[i][j+1].currentState == Cell::state:: EMPTY ||grid[i][j+1].currentState == Cell::state:: EXIT) && visited[i][j+1] !='v' && visited[i][j+1] != 'T')
    //        {
    //            j++;
    //            visited[i][j] = 'v';
    //        }

    //        //if none of these are possible (i.e. trapped) the 'v' in visisted is replaced with a 'T'
    //        //then all the 'v's in the array visited are erased
    //        else
    //        {
    //            visited[i][j] = 'T';

    //            for(int x=0; x<width; x++)
    //            {
    //                for(int y=0; y<height; y++)
    //                {
    //                    if(visited[x][y] == 'v')
    //                        visited[x][y] = '-';
    //                }
    //            }

    //            i = startX;
    //            j = startY;
    //        }


    //        if(visited[startX][startY] == 'T')
    //            return 0;
    //    }while(grid[i][j].currentState != Cell::state::EXIT);


    return true;
}
