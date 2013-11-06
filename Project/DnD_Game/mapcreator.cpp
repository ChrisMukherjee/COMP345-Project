#include "mapcreator.h"
#include "ui_mapcreator.h"
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>
#include "Grid.h"

MapCreator::MapCreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapCreator)
{
    ui->setupUi(this);
    height = 0;
    width = 0;
    ui->gridLayout->setSpacing(0);
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
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    QLabel *cell = new QLabel();
                    cell->setStyleSheet("border: 1px solid");
                  ui->gridLayout->addWidget(cell, i, j);

                    //ui->label1->setPixmap(QPixmap(":/images/wall.png"));
                }
            }
        }
        // If user is trying to change the size of a map
        else {
            // Display warning before proceding
            QMessageBox::StandardButton warn = QMessageBox::warning(this, "Warning", "Changing the size of the map will reset all cells. This may result in the loss of data. Are you sure you wish to continue?", QMessageBox::Yes|QMessageBox::No, QMessageBox::No);
            if (warn == QMessageBox::Yes) {
                // Delete all cells
                while (ui->gridLayout->count()) {
                    QLayoutItem * item = ui->gridLayout->takeAt(0);
                    QWidget * widget = item->widget();
                    widget->deleteLater();
                }
                height = h;
                width = w;
                // Create new cells
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                        QLabel *cell = new QLabel();
                        cell->setStyleSheet("border: 1px solid");
                      ui->gridLayout->addWidget(cell, i, j);

                        //ui->label1->setPixmap(QPixmap(":/images/wall.png"));
                    }
                }
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
