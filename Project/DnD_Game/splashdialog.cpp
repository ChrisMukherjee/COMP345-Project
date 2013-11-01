#include "splashdialog.h"
#include "ui_splashdialog.h"
#include "mainwindow.h"

SplashDialog::SplashDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SplashDialog)
{
    ui->setupUi(this);
}

SplashDialog::~SplashDialog()
{
    delete ui;
}

void SplashDialog::on_loadButton_clicked()
{
    char x = 'l';
    w = new MainWindow(0, x);
    w->show();
    this->close();
}

void SplashDialog::on_newButton_clicked()
{
    m = new MapCreator();
    m->show();
    this->close();
}
