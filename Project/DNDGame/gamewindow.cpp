#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QFileDialog>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    connect(this,SIGNAL(destroyed()),this->parent(),SLOT(destroy()));
}

GameWindow::GameWindow(QWidget *parent, int x) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    load = x;
    connect(this,SIGNAL(destroyed()),this->parent(),SLOT(close()));
}

GameWindow::~GameWindow()
{
    delete ui;
}


void GameWindow::on_action_Exit_triggered()
{
    this->close();
}

void GameWindow::showEvent ( QShowEvent * /* evt */ )
{
    if (load == 1)
    {
        QString mapName = QFileDialog::getOpenFileName(this, tr("Open File"), "/", tr("TXT Files (*.txt)"));
    }
}

void GameWindow::on_action_Load_triggered()
{
    QString mapName = QFileDialog::getOpenFileName(this, tr("Open File"), "/", tr("TXT Files (*.txt)"));
}

void GameWindow::on_action_Save_triggered()
{
    QString mapName = QFileDialog::getSaveFileName(this, tr("Save File"), "/", tr("TXT Files (*.txt)"));
}
