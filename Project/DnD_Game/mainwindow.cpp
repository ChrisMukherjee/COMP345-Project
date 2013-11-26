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

NewGame *n;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_action_New_triggered();
    level = 1;
    ui->gridLayout->setSpacing(0);
    setupDefaults();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupDefaults()
{
    height = 0;
    width = 0;
    startX = -1;
    startY = -1;
    endX = -1;
    endY = -1;
    map = NULL;
    mapChars = NULL;
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
    QString fullName = "C:/Users/chris/Documents/Visual Studio 2012/Projects/DnD_Game/characters/" + charName;
    std::string fileName = fullName.toStdString();
    std::ifstream f(fileName, std::ios::in);
    if (f.is_open())
    {
        f >> name;
        f >> image;
        f >> level;
        f >> baseStr;
        f >> baseDex;
        f >> baseCon;
        f >> baseInt;
        f >> baseWis;
        f >> baseCha;
        f >> effStr;
        f >> effDex;
        f >> effCon;
        f >> effInt;
        f >> effWis;
        f >> effCha;
        f >> modStr;
        f >> modDex;
        f >> modCon;
        f >> modInt;
        f >> modWis;
        f >> modCha;
        f >> ac;
        f >> attackBonus;
        f >> dmgBonus;
        f >> maxHP;
        f >> curHP;
        f >> gold;
        f.close();
        return true;
    }
    else
    {
        return false;
    }
}

void MainWindow::setMap(QString mapName)
{
    QString fullName = "C:/Users/chris/Documents/Visual Studio 2012/Projects/DnD_Game/maps/" + mapName;
    std::string fileName = fullName.toStdString();
    std::ifstream f(fileName, std::ios::in);
    if (f.is_open())
    {
        int lwidth, lheight;
        f >> lwidth >> lheight;

        populateMap(lwidth, lheight);

        QPixmap img;

        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; j++)
            {
                char temp;
                f >> temp;
                switch (temp)
                {
                case '.':
                    img = QPixmap(":/images/mud.png");
                    img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    map[i][j]->setPixmap(img);
                    mapChars[i][j] = '.';
                    break;
                case 'S':
                    img = QPixmap(":/images/startdoor.png");
                    img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    map[i][j]->setPixmap(img);
                    mapChars[i][j] = 'S';
                    startX = i;
                    startY = j;
                    break;
                case 'E':
                    img = QPixmap(":/images/enddoor.png");
                    img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    map[i][j]->setPixmap(img);
                    mapChars[i][j] = 'E';
                    endX = i;
                    endY = j;
                    break;
                case '#':
                    img = QPixmap(":/images/wall.png");
                    img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    map[i][j]->setPixmap(img);
                    mapChars[i][j] = '#';
                    break;
                case 'M':
                    img = chooseMonster();
                    img = QPixmap(":/images/rat.png");
                    img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    map[i][j]->setPixmap(img);
                    mapChars[i][j] = 'M';
                    break;
                case 'C':
                    img = QPixmap(":/images/chest.png");
                    img = img.scaled(map[i][j]->width(), map[i][j]->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    map[i][j]->setPixmap(img);
                    mapChars[i][j] = 'C';
                    break;
                }
            }
        }
        f.close();
    }
}

void MainWindow::populateMap(int w, int h)
{
    height = h;
    width = w;
    // Create 2D array
    map = new QLabel**[height];
    mapChars = new char*[height];
    for (int i = 0; i < height; i++) {
        map[i] = new QLabel*[width];
        mapChars[i] = new char[width];
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            QLabel* cell = new QLabel();
            cell->setStyleSheet("border: 1px solid");
            cell->setScaledContents(true);
            cell->setObjectName(QString::number((i*width)+j));
            map[i][j] = cell;
            mapChars[i][j] = '.';
            ui->gridLayout->addWidget(cell, i, j);
        }
    }
}

QPixmap MainWindow::chooseMonster()
{
    switch (level) {
    case 1:
        return QPixmap(":/images/rat.png");
        break;
    default:
        return QPixmap(":/images/rat.png");
        break;
    }
}

bool MainWindow::move(char direction)
{
    tmpX = playerX;
    tmpY = playerY;

    mapChars[playerX][playerY] = onCell;

    // If a monster is moved onto (killed), replace it with an empty cell when the player moves
    if (onCell == 'M')
        mapChars[playerX][playerY] = '=';

    if (direction == 'd' || direction == 'D')
        tmpY = tmpY+1;
    else if (direction == 'w' || direction == 'W')
        tmpX = tmpX-1;
    else if (direction == 'a' || direction == 'A')
        tmpY = tmpY-1;
    else if (direction == 's' || direction == 'S')
        tmpX = tmpX+1;

    // Moveable location
    if (mapChars[tmpX][tmpY] == '=' || mapChars[tmpX][tmpY] == 'C' || mapChars[tmpX][tmpY] == 'M') {
        // Reset Start cell if moving from start
        if(playerX == startX && playerY == startY)
            mapChars[playerX][playerY] = 'S';
        playerX = tmpX;
        playerY = tmpY;
    }
    // Moved onto End cell
    else if (mapChars[tmpX][tmpY] == 'E') {
        playerX = tmpX;
        playerY = tmpY;
        onCell = mapChars[playerX][playerY];
        mapChars[playerX][playerY] = '&';
        //        notify();
        return true;
    }

    onCell = mapChars[playerX][playerY];
    mapChars[playerX][playerY] = '&';

    //    notify();
    return false;
}

void MainWindow::playGame()
{
    playerX = startX;
    playerY = startY;
    mapChars[playerX][playerY] = '&';
}
