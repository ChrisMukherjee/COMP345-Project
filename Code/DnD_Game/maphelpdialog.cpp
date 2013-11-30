#include "maphelpdialog.h"
#include "ui_maphelpdialog.h"

MapHelpDialog::MapHelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapHelpDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
}

MapHelpDialog::~MapHelpDialog()
{
    delete ui;
}

void MapHelpDialog::on_okButton_clicked()
{
    this->close();
}
