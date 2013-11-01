#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(QWidget *parent, char x) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString mapName = QFileDialog::getOpenFileName(this, tr("Open File"), "/", tr("TXT Files (*.txt)"));
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
    QString mapName = QFileDialog::getOpenFileName(this, tr("Open File"), "/", tr("TXT Files (*.txt)"));
}

void MainWindow::on_action_Save_triggered()
{
    QString mapName = QFileDialog::getSaveFileName(this, tr("Save File"), "/", tr("TXT Files (*.txt)"));
}
