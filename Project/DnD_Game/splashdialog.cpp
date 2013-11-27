#include "splashdialog.h"
#include "ui_splashdialog.h"
#include "mainwindow.h"
#include "mapcreator.h"
#include "charcreator.h"

MainWindow *w;
MapCreator *m;
CharCreator *c;

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

void SplashDialog::on_newButton_clicked()
{
    w = new MainWindow();
    w->sp = this;
    w->show();
    this->hide();
}

void SplashDialog::on_mapButton_clicked()
{
    m = new MapCreator();
    m->sp = this;
    m->show();
    this->hide();
}

void SplashDialog::on_characterButton_clicked()
{
    c = new CharCreator();
    c->sp = this;
    c->show();
    this->hide();
}

void SplashDialog::on_quitButton_clicked()
{
    this->close();
}
