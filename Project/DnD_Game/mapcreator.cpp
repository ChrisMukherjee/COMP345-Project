#include "mapcreator.h"
#include "ui_mapcreator.h"
#include <QFileDialog>
#include <QWidget>
#include <QLabel>
#include "clicklabel.h"
#include <QMessageBox>
#include "maphelpdialog.h"
#include <QDebug>

MapCreator::MapCreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapCreator)
{
    ui->setupUi(this);
    height = 0;
    width = 0;
    startPos = -1;
    endPos = -1;
    ui->gridLayout->setSpacing(0);
    // Set Wall as automatically selected
    ui->wallImage->setStyleSheet("border: 2px solid red");
    selectType = 'W';
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

void MapCreator::on_actionE_xit_triggered()
{
    this->close();
}

void MapCreator::on_action_Open_triggered()
{
    QString mapName = QFileDialog::getOpenFileName(this, tr("Open Map"), "/", tr("MAP Files (*.map)"));
}

void MapCreator::on_action_Save_triggered()
{
    QString mapName = QFileDialog::getSaveFileName(this, tr("Save Map"), "/", tr("MAP Files (*.map)"));
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
                // Remove all pointers in QList
                while (!map.isEmpty()) {
                    map.removeLast();
                }
                // Delete all cells
                while (ui->gridLayout->count()) {
                    QLayoutItem * item = ui->gridLayout->takeAt(0);
                    delete item;
                }
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
            }
            else {
                QPixmap img = QPixmap(":/images/mud.png");
                img = img.scaled(currCell->width(), currCell->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                currCell->setPixmap(img);
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
    qDebug()<<index;
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
            }
            else {
                QPixmap img = QPixmap(":/images/mud.png");
                img = img.scaled(map.at(startPos)->width(), map.at(startPos)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                map.at(startPos)->setPixmap(img);
            }
        }
        QPixmap img = QPixmap(":/images/startdoor.png");
        img = img.scaled(map.at(index)->width(), map.at(index)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map.at(index)->setPixmap(img);
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
            }
            else {
                QPixmap img = QPixmap(":/images/mud.png");
                img = img.scaled(map.at(endPos)->width(), map.at(endPos)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                map.at(endPos)->setPixmap(img);
            }
        }
        QPixmap img = QPixmap(":/images/enddoor.png");
        img = img.scaled(map.at(index)->width(), map.at(index)->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        map.at(index)->setPixmap(img);
        endPos = index;
        return;
    }
    // Can only add doors or walls to the edges
    else if (index <= width || index%width == 0 || (index+1)%width == 0 || index >= (map.size()-width)) {
        qDebug()<<"Side Wall";
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
