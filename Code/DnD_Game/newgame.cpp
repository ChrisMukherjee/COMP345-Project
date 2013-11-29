#include "newgame.h"
#include "ui_newgame.h"
#include <QStringList>
#include <QDir>
#include <QList>
#include <QListWidgetItem>
#include <QCoreApplication>

NewGame::NewGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGame)
{
    ui->setupUi(this);
    populate_lists();
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
}

NewGame::~NewGame()
{
    delete ui;
}

void NewGame::populate_lists()
{
    QStringList charFilter("*.dcchar");
    QDir charDir(QCoreApplication::applicationDirPath() + "/characters/");
    QStringList characters = charDir.entryList(charFilter);
    for (int i = 0; i < characters.size(); i++) {
        ui->charList->addItem(characters.at(i));
    }
    ui->charList->setCurrentRow(0);

    QStringList mapFilter("*.dcmap");
    QDir mapDir(QCoreApplication::applicationDirPath() + "/maps/");
    QStringList maps = mapDir.entryList(mapFilter);
    for (int i = 0; i < maps.size(); i++) {
        ui->mapList->addItem(maps.at(i));
    }
    ui->mapList->setCurrentRow(0);
}

void NewGame::on_okButton_clicked()
{
    selectedChar = ui->charList->selectedItems();
    mw->setChar(selectedChar.at(0)->text());
    selectedMap = ui->mapList->selectedItems();
    mw->setMap(selectedMap.at(0)->text());
    mw->loaded = true;
    this->close();
}

void NewGame::on_cancelButton_clicked()
{
    this->close();
}
