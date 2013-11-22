#include "newgame.h"
#include "ui_newgame.h"
#include <QStringList>
#include <QDir>

NewGame::NewGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGame)
{
    ui->setupUi(this);
    populate_lists();
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
}

NewGame::~NewGame()
{
    delete ui;
}

void NewGame::populate_lists()
{
    QStringList charFilter("*.dcchar");
    QDir charDir("C:/Users/chris/Documents/Visual Studio 2012/Projects/DnD_Game/characters");
    QStringList characters = charDir.entryList(charFilter);
    for (int i = 0; i < characters.size(); i++) {
        ui->charList->addItem(characters.at(i));
    }
    ui->charList->setCurrentRow(0);

    QStringList mapFilter("*.dcmap");
    QDir mapDir("C:/Users/chris/Documents/Visual Studio 2012/Projects/DnD_Game/maps");
    QStringList maps = mapDir.entryList(mapFilter);
    for (int i = 0; i < maps.size(); i++) {
        ui->mapList->addItem(maps.at(i));
    }
    ui->mapList->setCurrentRow(0);
}

void NewGame::on_okButton_clicked()
{

}

void NewGame::on_cancelButton_clicked()
{
    this->close();
}
