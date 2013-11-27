#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <iostream>
#include <fstream>
#include <string>
#include <QCloseEvent>
#include "newgame.h"
#include <QMessageBox>
#include <QDebug>
#include "Character.h"
#include "Grid.h"
#include "InputEvent.h"
#include <vector>
#include "windows.h"

NewGame *n;
Fighter* player;
Grid* map;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_action_New_triggered();
    ui->gridLayout->setSpacing(0);
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

void MainWindow::setChar(QString charName)
{
    charName = "C:/Users/chris/Documents/Visual Studio 2012/Projects/DnD_Game/characters/" + charName;
    std::string fileName = charName.toStdString();
    player = new Fighter();
    player->loadCharacter(fileName);
    //    displayStats();
    //    displayInv();
}

void MainWindow::setMap(QString mapName)
{
    mapName = "C:/Users/chris/Documents/Visual Studio 2012/Projects/DnD_Game/maps/" + mapName;
    std::string fileName = mapName.toStdString();
    map = Grid::loadMap(fileName, player->level);
    displayMap();
}

void MainWindow::displayMap()
{
    char** testmap = map->getGrid();
    labelmap = new QLabel**[map->getWidth()];
    for (int i = 0; i < map->getWidth(); ++i)
        labelmap[i] = new QLabel*[map->getHeight()];

    for (int i = 0; i < map->getWidth(); ++i)
    {
        for (int j = 0; j < map->getHeight(); j++)
        {
            QLabel* cell = new QLabel();
            cell->setStyleSheet("border: 1px solid");
            cell->setScaledContents(true);
            labelmap[i][j] = cell;
            ui->gridLayout->addWidget(cell, i, j);
        }
    }

    QPixmap img;

    for (int i = 0; i < map->getWidth(); ++i)
    {
        for (int j = 0; j < map->getHeight(); j++)
        {
            switch (testmap[i][j])
            {
            case '.':
                img = QPixmap(":/images/mud.png");
                break;
            case 'S':
                img = QPixmap(":/images/startdoor.png");
                break;
            case 'E':
                img = QPixmap(":/images/enddoor.png");
                break;
            case '#':
                img = QPixmap(":/images/wall.png");
                break;
            case 'M':
                img = QPixmap(":/images/rat.png");
                break;
            case 'C':
                img = QPixmap(":/images/chest.png");
                break;
            case 'F':
                img = setFighterPic();
                break;
            default:
                img = QPixmap(":/images/mud.png");
                break;
            }
            img = img.scaled(labelmap[i][j]->width(), labelmap[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            labelmap[i][j]->setPixmap(img);
        }
    }
    start();
}

void MainWindow::start()
{
    map->startGame(player);

    std::vector<InputEvent> events;
    // Map w, a, s, d keypresses to Input Events
    events.push_back(InputEvent("up", 0x57));
    events.push_back(InputEvent("down", 0x53));
    events.push_back(InputEvent("left", 0x41));
    events.push_back(InputEvent("right", 0x44));
    // Map arrow keypresses to Input Events
    events.push_back(InputEvent("up", VK_UP));
    events.push_back(InputEvent("down", VK_DOWN));
    events.push_back(InputEvent("left", VK_LEFT));
    events.push_back(InputEvent("right", VK_RIGHT));
    // This one should always be last
    events.push_back(InputEvent("quit", VK_ESCAPE));

    displayMap();
}

QPixmap MainWindow::chooseMonster()
{
    switch (player->level) {
    case 1:
        return QPixmap(":/images/rat.png");
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        return QPixmap(":/images/rat.png");
        break;
    }
}

QPixmap MainWindow::setFighterPic()
{
    switch (player->picture) {
    case 1:
        return QPixmap(":/images/fighter-heavy.png");
        break;
    case 2:
        return QPixmap(":/images/fighter-mace.png");
        break;
    case 3:
        return QPixmap(":/images/fighter-shield.png");
        break;
    case 4:
        return QPixmap(":/images/fighter-sword.png");
        break;
    default:
        return QPixmap(":/images/fighter-heavy.png");
        break;
    }

}

