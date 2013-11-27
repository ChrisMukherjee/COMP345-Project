#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QWidget>
#include <QGridLayout>
#include <iostream>
#include <fstream>
#include <string>
#include <QCloseEvent>
#include "newgame.h"
#include <QMessageBox>
#include <QDebug>
#include "InputManager.h"
#include "InputEvent.h"
#include <vector>
#include "windows.h"

NewGame *n;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_action_New_triggered();
    ui->gridLayout->setSpacing(0);
    loaded = false;
    connect(n,SIGNAL(destroyed()), this, SLOT(start()));
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
}

void MainWindow::setMap(QString mapName)
{
    mapName = "C:/Users/chris/Documents/Visual Studio 2012/Projects/DnD_Game/maps/" + mapName;
    std::string fileName = mapName.toStdString();
    map = Grid::loadMap(fileName, player->level);
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

    scale_images();

    for (int i = 0; i < map->getWidth(); ++i)
    {
        for (int j = 0; j < map->getHeight(); j++)
        {
            switch (testmap[i][j])
            {
            case '.':
                labelmap[i][j]->setPixmap(mudSkin);
                break;
            case 'S':
                labelmap[i][j]->setPixmap(startSkin);
                break;
            case 'E':
                labelmap[i][j]->setPixmap(endSkin);
                break;
            case '#':
                labelmap[i][j]->setPixmap(wallSkin);
                break;
            case 'M':
                labelmap[i][j]->setPixmap(monsterSkin);
                break;
            case 'C':
                labelmap[i][j]->setPixmap(chestSkin);
                break;
            case 'F':
                labelmap[i][j]->setPixmap(playerSkin);
                break;
            default:
                labelmap[i][j]->setPixmap(mudSkin);
                break;
            }
        }
    }
    playGame();
}

void MainWindow::start()
{
    if (loaded == true) {
        setFighterPic();
        setMonsterPic();
        //    displayStats();
        //    displayInv();
        map->startGame(player);
        displayMap();
    }
}

// THIS DOES NOT WORK - FIX THIS ASAP
void MainWindow::playGame()
{
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

    std::string dir;

    //    while (dir != "quit") {
    //        qDebug()<<"in here";

    //        char** testmap = map->getGrid();
    //        QPixmap img;

    //        for (int i = 0; i < map->getWidth(); ++i)
    //        {
    //            for (int j = 0; j < map->getHeight(); j++)
    //            {
    //                switch (testmap[i][j])
    //                {
    //                case '.':
    //                    img = QPixmap(":/images/mud.png");
    //                    break;
    //                case 'S':
    //                    img = QPixmap(":/images/startdoor.png");
    //                    break;
    //                case 'E':
    //                    img = QPixmap(":/images/enddoor.png");
    //                    break;
    //                case '#':
    //                    img = QPixmap(":/images/wall.png");
    //                    break;
    //                case 'M':
    //                    img = QPixmap(":/images/rat.png");
    //                    break;
    //                case 'C':
    //                    img = QPixmap(":/images/chest.png");
    //                    break;
    //                case 'F':
    //                    img = playerSkin;
    //                    break;
    //                default:
    //                    img = QPixmap(":/images/mud.png");
    //                    break;
    //                }
    //                img = img.scaled(labelmap[i][j]->width(), labelmap[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    //                labelmap[i][j]->setPixmap(img);
    //            }
    //        }
    //        dir = InputManager::getInput(events);
    //        qDebug()<<"got event";

    //        map->getMove(player, dir, true);
    //        qDebug()<<"moved";

    //        qDebug()<<"end of loop";
    //    }
}

void MainWindow::setMonsterPic()
{
    switch (player->level) {
    case 1:
        monsterSkin = QPixmap(":/images/rat.png");
        monsterdeadSkin = QPixmap(":/images/rat_dead.png");
        break;
    case 2:
        monsterSkin = QPixmap(":/images/goblin.png");
        monsterdeadSkin = QPixmap(":/images/goblin_dead.png");
        break;
    case 3:
        monsterSkin = QPixmap(":/images/gargoyle.png");
        monsterdeadSkin = QPixmap(":/images/gargoyle_dead.png");
        break;
    case 4:
        monsterSkin = QPixmap(":/images/skeleton.png");
        monsterdeadSkin = QPixmap(":/images/skeleton_dead.png");
        break;
    case 5:
        monsterSkin = QPixmap(":/images/mage.png");
        monsterdeadSkin = QPixmap(":/images/mage_dead.png");
        break;
    default:
        monsterSkin = QPixmap(":/images/skeleton.png");
        monsterdeadSkin = QPixmap(":/images/skeleton_dead.png");
        break;
    }
}

void MainWindow::setFighterPic()
{
    switch (player->picture) {
    case 1:
        playerSkin = QPixmap(":/images/fighter_sword.png");
        break;
    case 2:
        playerSkin = QPixmap(":/images/fighter_shield.png");
        break;
    case 3:
        playerSkin = QPixmap(":/images/fighter_mace.png");
        break;
    case 4:
        playerSkin = QPixmap(":/images/fighter_heavy.png");
        break;
    case 5:
        playerSkin = QPixmap(":/images/fighter_bow.png");
        break;
    default:
        playerSkin = QPixmap(":/images/fighter_sword.png");
        break;
    }
}

void MainWindow::scale_images()
{
    QPixmap img;
    img = QPixmap(":/images/mud.png");
    img = img.scaled(labelmap[0][0]->width(), labelmap[0][0]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    mudSkin = img;
    img = QPixmap(":/images/wall.png");
    img = img.scaled(labelmap[0][0]->width(), labelmap[0][0]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    wallSkin = img;
    img = QPixmap(":/images/chest.png");
    img = img.scaled(labelmap[0][0]->width(), labelmap[0][0]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    chestSkin = img;
    img = QPixmap(":/images/chest_empty.png");
    img = img.scaled(labelmap[0][0]->width(), labelmap[0][0]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    chestemptySkin = img;
    img = QPixmap(":/images/startdoor.png");
    img = img.scaled(labelmap[0][0]->width(), labelmap[0][0]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    startSkin = img;
    img = QPixmap(":/images/enddoor.png");
    img = img.scaled(labelmap[0][0]->width(), labelmap[0][0]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    endSkin = img;
    img = playerSkin;
    img = img.scaled(labelmap[0][0]->width(), labelmap[0][0]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    playerSkin = img;
    img = monsterSkin;
    img = img.scaled(labelmap[0][0]->width(), labelmap[0][0]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    monsterSkin = img;
    img = monsterdeadSkin;
    img = img.scaled(labelmap[0][0]->width(), labelmap[0][0]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    monsterdeadSkin = img;
}
