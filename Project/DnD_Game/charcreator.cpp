#include "charcreator.h"
#include "ui_charcreator.h"

CharCreator::CharCreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CharCreator)
{
    ui->setupUi(this);
}

CharCreator::~CharCreator()
{
    delete ui;
}
