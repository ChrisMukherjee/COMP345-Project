#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(char x, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (x == 'l') {
        QString mapName = QFileDialog::getOpenFileName(this, tr("Load Game"), "/", tr("GAME Files (*.gam)"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionE_xit_triggered()
{
    this->close();
}

void MainWindow::on_action_Load_triggered()
{
    QString mapName = QFileDialog::getOpenFileName(this, tr("Load Game"), "/", tr("GAME Files (*.gam)"));
}

void MainWindow::on_action_Save_triggered()
{
    QString mapName = QFileDialog::getSaveFileName(this, tr("Save Game"), "/", tr("GAME Files (*.gam)"));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    this->sp->show();
    event->accept();
}
