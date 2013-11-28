#include "mapcreator.h"
#include "ui_mapcreator.h"
#include <QFileDialog>
#include <QLabel>
#include <QGridLayout>
#include <iostream>
#include <fstream>
#include <string>
#include <QMessageBox>
#include "maphelpdialog.h"
#include <QCloseEvent>

MapCreator::MapCreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapCreator)
{
    ui->setupUi(this);
    ui->loadingLabel->setVisible(false);
    ui->gridLayout->setSpacing(0);
    ui->templateCombo->addItem("None");
    ui->templateCombo->addItem("Arena");
//    ui->templateCombo->addItem("Maze");
    setupDefaults();
    // Connect options to click signal
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
    startX = -1;
    startY = -1;
    endX = -1;
    endY = -1;
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
    ui->templateCombo->setCurrentIndex(0);
    map = NULL;
    mapChars = NULL;
}

void MapCreator::on_actionE_xit_triggered()
{
    this->close();
}

void MapCreator::on_action_Open_triggered()
{
    // If user has edited map opened
    if (map != NULL) {
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
    else {
        deleteMap();
        setupDefaults();
    }
    QString mapName = QFileDialog::getOpenFileName(this, tr("Open Map"), "C:/Users/chris/Documents/Visual Studio 2012/Projects/DnD_Game/maps", tr("MAP Files (*.dcmap)"));
    std::string fileName = mapName.toStdString();
    std::ifstream f(fileName, std::ios::in);
    if (f.is_open())
    {
        int lwidth, lheight;
        f >> lwidth >> lheight;
        ui->wValue->setValue(width);
        ui->hValue->setValue(height);

        populateMap(lwidth, lheight);

        QPixmap img;

        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; j++)
            {
                char temp;
                f >> temp;
                switch (temp)
                {
                case '.':
                    img = QPixmap(":/images/mud.png");
                    img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    map[i][j]->setPixmap(img);
                    mapChars[i][j] = '.';
                    break;
                case 'S':
                    img = QPixmap(":/images/startdoor.png");
                    img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    map[i][j]->setPixmap(img);
                    mapChars[i][j] = 'S';
                    startX = i;
                    startY = j;
                    break;
                case 'E':
                    img = QPixmap(":/images/enddoor.png");
                    img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    map[i][j]->setPixmap(img);
                    mapChars[i][j] = 'E';
                    endX = i;
                    endY = j;
                    break;
                case '#':
                    img = QPixmap(":/images/wall.png");
                    img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    map[i][j]->setPixmap(img);
                    mapChars[i][j] = '#';
                    break;
                case 'M':
                    img = QPixmap(":/images/rat.png");
                    img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    map[i][j]->setPixmap(img);
                    mapChars[i][j] = 'M';
                    break;
                case 'C':
                    img = QPixmap(":/images/chest.png");
                    img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    map[i][j]->setPixmap(img);
                    mapChars[i][j] = 'C';
                    break;
                }
            }
        }
        f.close();
    }
}

bool MapCreator::on_action_Save_triggered()
{
    if (validateMap()) {
        QString mapName = QFileDialog::getSaveFileName(this, tr("Save Map"), "C:/Users/chris/Documents/Visual Studio 2012/Projects/DnD_Game/maps", tr("MAP Files (*.dcmap)"));
        std::string fileName = mapName.toStdString();
        std::ofstream f(fileName, std::ios::out);
        if (f.is_open())
        {
            f << width << std::endl << height << std::endl;

            for (int i = 0; i < height; ++i)
            {
                for (int j = 0; j < width; ++j)
                {
                    if (mapChars[i][j] == 'M') {
                        numMonsters++;
                    }
                }
            }

            f << numMonsters << std::endl;

            for (int i = 0; i < height; ++i)
            {
                for (int j = 0; j < width; ++j)
                {
                    f << mapChars[i][j] << " ";
                }
                f << std::endl;
            }
            f.close();
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

void MapCreator::on_action_New_triggered()
{
    // If user has edited map opened
    if (map != NULL) {
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
    ui->loadingLabel->setVisible(true);
    populateMap(w, h);
    ui->loadingLabel->setVisible(false);
}

void MapCreator::populateMap(int w, int h)
{
    // Check for changes first
    if (h != height || w != width) {
        if (height == 0 && width == 0) {
            height = h;
            width = w;
            // Create 2D array
            map = new ClickLabel**[height];
            mapChars = new char*[height];
            for (int i = 0; i < height; i++) {
                map[i] = new ClickLabel*[width];
                mapChars[i] = new char[width];
            }
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
                // Create 2D array
                map = new ClickLabel**[height];
                mapChars = new char*[height];
                for (int i = 0; i < height; i++) {
                    map[i] = new ClickLabel*[width];
                    mapChars[i] = new char[width];
                }
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
            ClickLabel* cell = new ClickLabel();
            cell->setStyleSheet("border: 1px solid");
            cell->setScaledContents(true);
            cell->setObjectName(QString::number((i*width)+j));
            map[i][j] = cell;
            mapChars[i][j] = '.';
            ui->gridLayout->addWidget(cell, i, j);
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ClickLabel* currCell = map[i][j];
            connect(map[i][j], SIGNAL(clicked()), this, SLOT(map_label_clicked()));

            if (i == 0 || j == 0 || i == height-1 || j == width-1) {
                QPixmap img = QPixmap(":/images/wall.png");
                img = img.scaled(currCell->width(), currCell->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                currCell->setPixmap(img);
                mapChars[i][j] = '#';
            }
            else {
                QPixmap img = QPixmap(":/images/mud.png");
                img = img.scaled(currCell->width(), currCell->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                currCell->setPixmap(img);
                mapChars[i][j] = '.';
            }
        }
    }
    if (ui->templateCombo->currentText() == "Arena") {
        QPixmap img = QPixmap(":/images/chest.png");
        img = img.scaled(map[height/2][width/2]->width(), map[height/2][width/2]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map[height/2][width/2]->setPixmap(img);
        mapChars[height/2][width/2] = 'C';

        img = QPixmap(":/images/rat.png");
        img = img.scaled(map[1][width/2]->width(), map[1][width/2]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map[1][width/2]->setPixmap(img);
        mapChars[1][width/2] = 'M';

        img = QPixmap(":/images/enddoor.png");
        img = img.scaled(map[0][width/2]->width(), map[0][width/2]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map[0][width/2]->setPixmap(img);
        mapChars[0][width/2] = 'E';
        endX = 0;
        endY = width/2;

        img = QPixmap(":/images/startdoor.png");
        img = img.scaled(map[height-1][width/2]->width(), map[height-1][width/2]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map[height-1][width/2]->setPixmap(img);
        mapChars[height-1][width/2] = 'S';
        startX = height-1;
        startY = width/2;
    }
}

void MapCreator::on_action_Help_triggered()
{
    MapHelpDialog *help = new MapHelpDialog();
    help->show();
}

void MapCreator::map_label_clicked()
{
    int x = 0, y = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j]->objectName() == QObject::sender()->objectName()) {
                x = i;
                y = j;
                break;
            }
        }
    }

    if (selectType == 'W') {
        setWall(x, y);
    }
    else if (selectType == 'S') {
        setStart(x, y);
    }
    else if (selectType == 'E') {
        setEnd(x, y);
    }
    else if (selectType == 'C') {
        setChest(x, y);
    }
    else if (selectType == 'M') {
        setMonster(x, y);
    }
    else if (selectType == '-') {
        setEmpty(x, y);
    }
}

bool MapCreator::setWall(int x, int y)
{
    // Reset Start and End locations, if replacing one
    if (mapChars[x][y] == 'S') {
        startX = -1;
        startY = -1;
    }
    // Reset Start and End locations, if replacing one
    else if (mapChars[x][y] == 'E') {
        endX = -1;
        endY = -1;
    }
    QPixmap img = QPixmap(":/images/wall.png");
    img = img.scaled(map[x][y]->width(), map[x][y]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    map[x][y]->setPixmap(img);
    mapChars[x][y] = '#';
    return true;
}

bool MapCreator::setStart(int x, int y)
{
    QPixmap img;
    // Cannot edit the corners of the map
    if ((x == 0 && y == 0) || (x == 0 && y == width-1) || (x == height-1 && y == 0)|| (x == height-1 && y == width-1)) {
        return false;
    }
    // Start is added in a special way
    // Must make sure to only have one Start
    else {
        if (startX != -1 || startY != -1) {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (mapChars[i][j] == 'S') {
                        if ((j == 0 || j == width-1) || (i == 0 || i == height-1)) {
                            img = QPixmap(":/images/wall.png");
                            img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                            map[i][j]->setPixmap(img);
                            mapChars[i][j] = '#';
                        }
                        else {
                            img = QPixmap(":/images/mud.png");
                            img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                            map[i][j]->setPixmap(img);
                            mapChars[i][j] = '.';
                        }
                        break;
                    }
                }
            }
        }
        img = QPixmap(":/images/startdoor.png");
        img = img.scaled(map[x][y]->width(), map[x][y]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map[x][y]->setPixmap(img);
        mapChars[x][y] = 'S';
        startX = x;
        startY = y;
        return true;
    }
}

bool MapCreator::setEnd(int x, int y)
{
    QPixmap img;
    // Cannot edit the corners of the map
    if ((x == 0 && y == 0) || (x == 0 && y == width-1) || (x == height-1 && y == 0)|| (x == height-1 && y == width-1)) {
        return false;
    }
    // End is added in a special way
    // Must make sure to only have one End
    else {
        if (endX != -1 || endY != -1) {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (mapChars[i][j] == 'E') {
                        if ((j == 0 || j == width-1) || (i == 0 || i == height-1)) {
                            img = QPixmap(":/images/wall.png");
                            img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                            map[i][j]->setPixmap(img);
                            mapChars[i][j] = '#';
                        }
                        else {
                            img = QPixmap(":/images/mud.png");
                            img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                            map[i][j]->setPixmap(img);
                            mapChars[i][j] = '.';
                        }
                        break;
                    }
                }
            }
        }
        img = QPixmap(":/images/enddoor.png");
        img = img.scaled(map[x][y]->width(), map[x][y]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map[x][y]->setPixmap(img);
        mapChars[x][y] = 'E';
        endX = x;
        endY = y;
        return true;
    }
}

bool MapCreator::setChest(int x, int y) {
    // Cannot edit the corners of the map
    if ((x == 0 && y == 0) || (x == 0 && y == width-1) || (x == height-1 && y == 0)|| (x == height-1 && y == width-1)) {
        return false;
    }
    // Can only add doors or walls to the edges
    else if ((x == 0 || x == width-1) || (y == 0 || y == height-1)) {
        return false;
    }
    else {
        // Reset Start and End locations, if replacing one
        if (mapChars[x][y] == 'S') {
            startX = -1;
            startY = -1;
        }
        // Reset Start and End locations, if replacing one
        else if (mapChars[x][y] == 'E') {
            endX = -1;
            endY = -1;
        }
        QPixmap img = QPixmap(":/images/chest.png");
        img = img.scaled(map[x][y]->width(), map[x][y]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map[x][y]->setPixmap(img);
        mapChars[x][y] = 'C';
        return true;
    }
}

bool MapCreator::setMonster(int x, int y) {
    // Cannot edit the corners of the map
    if ((x == 0 && y == 0) || (x == 0 && y == width-1) || (x == height-1 && y == 0)|| (x == height-1 && y == width-1)) {
        return false;
    }
    // Can only add doors or walls to the edges
    else if ((x == 0 || x == width-1) || (y == 0 || y == height-1)) {
        return false;
    }
    else {
        // Reset Start and End locations, if replacing one
        if (mapChars[x][y] == 'S') {
            startX = -1;
            startY = -1;
        }
        // Reset Start and End locations, if replacing one
        else if (mapChars[x][y] == 'E') {
            endX = -1;
            endY = -1;
        }
        QPixmap img = QPixmap(":/images/rat.png");
        img = img.scaled(map[x][y]->width(), map[x][y]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map[x][y]->setPixmap(img);
        mapChars[x][y] = 'M';
        return true;
    }
}

bool MapCreator::setEmpty(int x, int y) {
    // Cannot edit the corners of the map
    if ((x == 0 && y == 0) || (x == 0 && y == width-1) || (x == height-1 && y == 0)|| (x == height-1 && y == width-1)) {
        return false;
    }
    // Can only add doors or walls to the edges
    else if ((x == 0 || x == width-1) || (y == 0 || y == height-1)) {
        return false;
    }
    else {
        // Reset Start and End locations, if replacing one
        if (mapChars[x][y] == 'S') {
            startX = -1;
            startY = -1;
        }
        // Reset Start and End locations, if replacing one
        else if (mapChars[x][y] == 'E') {
            endX = -1;
            endY = -1;
        }
        QPixmap img = QPixmap(":/images/mud.png");
        img = img.scaled(map[x][y]->width(), map[x][y]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map[x][y]->setPixmap(img);
        mapChars[x][y] = '.';
        return true;
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
    // Delete 2D arrays
    for (int i = 0; i < height; i++) {
        delete[] map[i];
        delete[] mapChars[i];
    }
    delete[] map;
    delete[] mapChars;
    map = NULL;
    mapChars = NULL;

    // Delete all cells
    while (QLayoutItem* item = ui->gridLayout->takeAt(0))
    {
        if (QWidget* widget = item->widget()) {
            ui->gridLayout->removeWidget(widget);
        }
        ui->gridLayout->removeItem(item);
        delete item;
    }
}

bool MapCreator::validateMap()
{
    // First check to make sure the map has a Start and End
    if (startX == -1 || startY == -1 || endX == -1 || endY == -1) {
        QMessageBox::StandardButton err = QMessageBox::critical(this, "Invalid Map!", "This map is not valid. Your map must have one (S)tart cell and one (E)nd cell.", QMessageBox::Ok);
        return false;
    }

    // Set up for map traversal
    // Create another array so that user's map remains unchanged
    char** visited = new char*[height];
    for (int k = 0; k < height; k++)
        visited[k] = new char[width];

    // Fill the new array with empty spaces (=)
    for (int k = 0; k < height; k++) {
        for (int l = 0; l < width; l++)
            visited[k][l] = '=';
    }

    int i = startX;
    int j = startY;

    // Mark visited indices with a V character
    visited[i][j] = 'V';

    while (i != endX || j != endY) {
        // Try going right
        if (j+1 < width && mapChars[i][j+1] != '#' && visited[i][j+1] != 'V' && visited[i][j+1] != 'Z') {
            j++;
            visited[i][j] = 'V';
        }
        // Try going up
        else if (i-1 >= 0 && mapChars[i-1][j] != '#' && visited[i-1][j] != 'V' && visited[i-1][j] != 'Z') {
            i--;
            visited[i][j] = 'V';
        }
        // Try going left
        else if (j-1 >= 0 && mapChars[i][j-1] != '#' && visited[i][j-1] != 'V' && visited[i][j-1] != 'Z') {
            j--;
            visited[i][j] = 'V';
        }
        // Try going down
        else if (i+1 < height && mapChars[i+1][j] != '#' && visited[i+1][j] != 'V' && visited[i+1][j] != 'Z') {
            i++;
            visited[i][j] = 'V';
        }
        // If none of the above movements are possible, we have reached a dead end
        else {
            // Mark dead end indices with a Z character
            visited[i][j] = 'Z';

            // Change all the (V)isited indices back into empty (=) cells because they may need to be used for another traversal
            for (int k = 0; k < height; k++) {
                for (int l = 0; l < width; l++) {
                    if (visited[k][l] == 'V') {
                        visited[k][l] = '=';
                    }
                }
            }

            // Reset i, j variables
            i = startX;
            j = startY;
        }

        // Invalid map (no way to get from Start to End)
        if (visited[startX][startY] == 'Z') {
            QMessageBox::StandardButton err = QMessageBox::critical(this, "Invalid Map!", "This map is not valid. Please review it and fix any errors!", QMessageBox::Ok);
            for (int i = 0; i < height; i++) {
                delete[] visited[i];
            }
            delete[] visited;
            return false;
        }
    }
    for (int i = 0; i < height; i++) {
        delete[] visited[i];
    }
    delete[] visited;
    // If the loop exits, we have reached the end of the map
    return true;
}

void MapCreator::closeEvent(QCloseEvent *event)
{
    // If user has edited map opened
    if (map != NULL) {
        // Display warning about unsaved map
        QMessageBox::StandardButton warn = QMessageBox::warning(this, "Save Map?", "Do you want to save the changes you have made to the current map?", QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel, QMessageBox::Yes);
        if (warn == QMessageBox::Yes) {
            if (!on_action_Save_triggered()) {
                event->ignore();
                return;
            }
            deleteMap();
            this->sp->show();
            event->accept();
        }
        else if (warn == QMessageBox::Cancel) {
            event->ignore();
        }
        else if (warn == QMessageBox::No) {
            deleteMap();
            this->sp->show();
            event->accept();
        }
    }
    else {
        deleteMap();
        this->sp->show();
        event->accept();
    }
}
