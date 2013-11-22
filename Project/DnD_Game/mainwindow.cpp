#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QCloseEvent>
#include "newgame.h"

NewGame *n;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_action_New_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionE_xit_triggered()
{
    this->close();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    this->sp->show();
    event->accept();
}

void MainWindow::on_action_New_triggered()
{
    n = new NewGame();
    n->mw = this;
    n->show();
}
