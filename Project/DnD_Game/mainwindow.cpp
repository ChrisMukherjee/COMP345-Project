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
#include "windows.h"
#include "CharacterObserver.h"
#include "GridObserver.h"
#include <QCoreApplication>
#include <QScrollBar>
#include <ctime>

NewGame *n;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(static_cast<unsigned>(time(NULL)));
    this->setAttribute(Qt::WA_DeleteOnClose);
    on_action_New_triggered();
    ui->gridLayout->setSpacing(0);
    loaded = false;
    dead = false;
    connect(n,SIGNAL(destroyed()), this, SLOT(start()));
    connect(ui->invList,SIGNAL(doubleClicked(QModelIndex)), this, SLOT(equip()));
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
    dead = true;
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
    charFName = "C:/Users/chris/Documents/Visual Studio 2012/Projects/DnD_Game/characters/" + charName;
    std::string fileName = charFName.toStdString();
    player = new Fighter();
    player->loadCharacter(fileName);
}

void MainWindow::setMap(QString mapName)
{
    mapFName = "C:/Users/chris/Documents/Visual Studio 2012/Projects/DnD_Game/maps/" + mapName;
    std::string fileName = mapFName.toStdString();
    map = Grid::loadMap(fileName, player->level);
}

void MainWindow::displayStart()
{
    char** testmap = map->getGrid();
    labelmap = new QLabel**[map->getWidth()];
    for (int i = 0; i < map->getWidth(); ++i)
        labelmap[i] = new QLabel*[map->getHeight()];

    for (int i = 0; i < map->getHeight(); ++i)
    {
        for (int j = 0; j < map->getWidth(); j++)
        {
            QLabel* cell = new QLabel();
            cell->setStyleSheet("border: 1px solid");
            cell->setScaledContents(true);
            labelmap[j][i] = cell;
            ui->gridLayout->addWidget(cell, i, j);
        }
    }

    scale_images();

    for (int i = 0; i < map->getHeight(); ++i)
    {
        for (int j = 0; j < map->getWidth(); j++)
        {
            switch (testmap[j][i])
            {
            case '.':
                labelmap[j][i]->setPixmap(mudSkin);
                break;
            case 'S':
                labelmap[j][i]->setPixmap(startSkin);
                break;
            case 'E':
                labelmap[j][i]->setPixmap(endSkin);
                break;
            case '#':
                labelmap[j][i]->setPixmap(wallSkin);
                break;
            case 'M':
                labelmap[j][i]->setPixmap(monsterSkin);
                break;
            case 'C':
                labelmap[j][i]->setPixmap(chestSkin);
                break;
            case 'F':
                labelmap[j][i]->setPixmap(playerSkin);
                break;
            default:
                labelmap[j][i]->setPixmap(mudSkin);
                break;
            }
        }
    }
    ui->textBrowser->verticalScrollBar()->setSliderPosition(ui->textBrowser->verticalScrollBar()->maximum());
    QCoreApplication::processEvents();
    playGame();
}

void MainWindow::displayMap()
{
    char** testmap = map->getGrid();

    for (int i = 0; i < map->getHeight(); ++i)
    {
        for (int j = 0; j < map->getWidth(); j++)
        {
            switch (testmap[j][i])
            {
            case '.':
                labelmap[j][i]->setPixmap(mudSkin);
                break;
            case 'S':
                labelmap[j][i]->setPixmap(startSkin);
                break;
            case 'E':
                labelmap[j][i]->setPixmap(endSkin);
                break;
            case '#':
                labelmap[j][i]->setPixmap(wallSkin);
                break;
            case 'M':
                labelmap[j][i]->setPixmap(monsterSkin);
                break;
            case 'm':
                labelmap[j][i]->setPixmap(monsterdeadSkin);
                break;
            case 'C':
                labelmap[j][i]->setPixmap(chestSkin);
                break;
            case 'c':
                labelmap[j][i]->setPixmap(chestemptySkin);
                break;
            case 'F':
                labelmap[j][i]->setPixmap(playerSkin);
                break;
            default:
                labelmap[j][i]->setPixmap(mudSkin);
                break;
            }
        }
    }
    ui->textBrowser->verticalScrollBar()->setSliderPosition(ui->textBrowser->verticalScrollBar()->maximum());
    QCoreApplication::processEvents();
}

void MainWindow::start()
{
    if (loaded == true) {
        setFighterPic();
        setMonsterPic();
        ui->action_New->setEnabled(false);
        map->startGame(player);
        displayStart();
    }
}

void MainWindow::playGame()
{
    ui->textBrowser->append("Initiative rolls:");

    for (size_t i = 0; i < map->actors.size(); i++)
    {
        QString output(QString::fromStdString(map->actors[i]->name + ": " + std::to_string(map->actors[i]->initiative)));
        ui->textBrowser->append(output);
    }

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

    player->inv.push_back(new Equippable(Equippable::SWORD, player->level));

    ui->statBrowser->setText(QString::fromStdString(player->characterSheetToString()));
    updateInvList();
    while ((!map->isEnd(player->x, player->y) || !map->allEnemiesDead) && !dead)
    {
        ui->statBrowser->setText(QString::fromStdString(player->characterSheetToString()));
        updateInvList();
        for (size_t i = 0; i < map->actors.size(); i++)
        {
            ui->statBrowser->setText(QString::fromStdString(player->characterSheetToString()));
            updateInvList();
            Character* current = map->actors[i];
            current->movesLeft = 6;
            if (current->name != player->name)
            {
                while (current->movesLeft > 0)
                {
                    int d = roll(4);
                    if (d == 1) {
                        if (map->tryMove(current, "up", false) == true) {
                            displayMap();
                        }
                    }
                    else if (d == 2) {
                        if (map->tryMove(current, "down", false) == true) {
                            displayMap();
                        }
                    }
                    else if (d == 3) {
                        if (map->tryMove(current, "right", false) == true) {
                            displayMap();
                        }
                    }
                    else if (d == 4) {
                        if (map->tryMove(current, "left", false) == true) {
                            displayMap();
                        }
                    }
                    if (player->curHP <= 0)
                    {
                        dead = true;
                        QMessageBox::StandardButton err = QMessageBox::critical(this, "Game Over!", "You have died! Please play again.", QMessageBox::Ok);
                        break;
                    }
                }
                if (current->attackinfo != "")
                    ui->textBrowser->append(QString::fromStdString(current->attackinfo));
            }
            else
            {
                ui->textBrowser->append("\nYour turn!\n");
                while (player->movesLeft > 0)
                {
                    playerTurn();
                    if (map->isEnd(player->x, player->y) && map->allEnemiesDead) {
                        break;
                    }
                    if (map->tryExit)
                        ui->textBrowser->append("The exit is locked. Defeat all enemies to unlock it.");
                    ui->statBrowser->setText(QString::fromStdString(player->characterSheetToString()));
                    updateInvList();
                }
                if (current->attackinfo != "")
                    ui->textBrowser->append(QString::fromStdString(player->attackinfo));
            }
            ui->statBrowser->setText(QString::fromStdString(player->characterSheetToString()));
            updateInvList();
        }
    }

    if (!dead) {
        QMessageBox::StandardButton info = QMessageBox::information(this, "Congratulations!", "You have beaten this level and LEVELED UP!", QMessageBox::Ok);

        player->levelUp();
        std::string fileName = charFName.toStdString();
        player->saveCharacter(fileName);
    }

    this->close();
}

void MainWindow::playerTurn()
{
    std::string move;

    move = InputManager::getInput(events);
    if (map->tryMove(player, move, true)) {
        displayMap();
    }
}

void MainWindow::setMonsterPic()
{
    switch (player->level) {
    case 1:
        monsterSkin = QPixmap(":/images/rat.png");
        monsterdeadSkin = QPixmap(":/images/rat_dead.png");
        map->monsterName = "Rat";
        break;
    case 2:
        monsterSkin = QPixmap(":/images/goblin.png");
        monsterdeadSkin = QPixmap(":/images/goblin_dead.png");
        map->monsterName = "Goblin";
        break;
    case 3:
        monsterSkin = QPixmap(":/images/gargoyle.png");
        monsterdeadSkin = QPixmap(":/images/gargoyle_dead.png");
        map->monsterName = "Gargoyle";
        break;
    case 4:
        monsterSkin = QPixmap(":/images/skeleton.png");
        monsterdeadSkin = QPixmap(":/images/skeleton_dead.png");
        map->monsterName = "Skeleton";
        break;
    case 5:
        monsterSkin = QPixmap(":/images/mage.png");
        monsterdeadSkin = QPixmap(":/images/mage_dead.png");
        map->monsterName = "Mage";
        break;
    default:
        monsterSkin = QPixmap(":/images/devil.png");
        monsterdeadSkin = QPixmap(":/images/devil_dead.png");
        map->monsterName = "Devil";
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

void MainWindow::updateInvList()
{
    ui->invList->clear();
    QStringList items;
    for (int i = 0; i < player->inv.size(); i++)
    {
        std::string extra = "";
        if (player->inv[i]->getEqStatus())
        {
            extra = " *";
        }
        items.push_back(QString::fromStdString(player->inv[i]->getName() + extra));
        ui->invList->addItem(items.at(i));
    }
    for (int i = 0; i < ui->invList->count(); i++)
    {
        if (player->inv[i]->getEqStatus())
        {
            ui->invList->item(i)->setTextColor(Qt::blue);
        }
    }
}

void MainWindow::equip()
{
    int row = ui->invList->currentRow();
    if (!player->inv[row]->getEqStatus())
        player->equip(*player->inv[row]);
    else
    {
        Equippable::ItemType t = player->inv[row]->getIType();
        if (t > 0)
        {
            t = static_cast<Equippable::ItemType>(t - 1);
        }
        player->unequip(t);
    }
    updateInvList();
    ui->statBrowser->setText(QString::fromStdString(player->characterSheetToString()));
}
