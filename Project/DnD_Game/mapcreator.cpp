#include "mapcreator.h"
#include "ui_mapcreator.h"

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
