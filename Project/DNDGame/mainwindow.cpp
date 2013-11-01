#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newButton_clicked()
{

}

void MainWindow::on_loadButton_clicked()
{
    w = new GameWindow(this, 1);
    w->show();
//    this->hide();
}
