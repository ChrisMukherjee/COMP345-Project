#include "mapcreator.h"
#include "ui_mapcreator.h"
#include <QFileDialog>

MapCreator::MapCreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapCreator)
{
    ui->setupUi(this);
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
    int width = ui->wValue->value();
    int height = ui->hValue->value();

}
