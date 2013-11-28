#include "charcreator.h"
#include "ui_charcreator.h"
#include <QFileDialog>
#include <QLabel>
#include <QGridLayout>
#include <iostream>
#include <fstream>
#include <string>
#include <QMessageBox>
//#include "charhelpdialog.h"
#include <QCloseEvent>
#include <QSpinBox>
#include "FighterDirector.h"
#include "FighterBuilder.h"
#include "BullyFighterBuilder.h"
#include "NimbleFighterBuilder.h"
#include "TankFighterBuilder.h"

CharCreator::CharCreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CharCreator)
{
    ui->setupUi(this);
    ui->templateCombo->addItem("None");
    ui->templateCombo->addItem("Bully");
    ui->templateCombo->addItem("Nimble");
    ui->templateCombo->addItem("Tank");
    // Connect options to click signal
    connect(ui->sprite1, SIGNAL(clicked()), this, SLOT(change_selected()));
    connect(ui->sprite2, SIGNAL(clicked()), this, SLOT(change_selected()));
    connect(ui->sprite3, SIGNAL(clicked()), this, SLOT(change_selected()));
    connect(ui->sprite4, SIGNAL(clicked()), this, SLOT(change_selected()));
    connect(ui->sprite5, SIGNAL(clicked()), this, SLOT(change_selected()));
    connect(ui->templateCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(buildTemplate()));
    c = new Fighter();
    setupDefaults();
}

CharCreator::~CharCreator()
{
    delete ui;
}

void CharCreator::setupDefaults()
{
    // Set Sprite1 as automatically selected
    ui->sprite1->setStyleSheet("border: 2px solid red");
    ui->sprite2->setStyleSheet("border: none");
    ui->sprite3->setStyleSheet("border: none");
    ui->sprite4->setStyleSheet("border: none");
    ui->sprite5->setStyleSheet("border: none");
    rollClicked = false;
    ui->levelButton->setEnabled(false);
    selectImage = 1;
    c->picture = 1;
    ui->nameValue->setText("");
    ui->levelValue->setText("1");
    ui->maxHPValue->setText(QString::fromStdString(std::to_string(Fighter::HP_START)));
    ui->atkbonusValue->setText("1");
    ui->templateCombo->setCurrentIndex(0);
    ui->strValue->setText("0");
    ui->dexValue->setText("0");
    ui->conValue->setText("0");
    ui->intValue->setText("0");
    ui->wisValue->setText("0");
    ui->chaValue->setText("0");
    ui->strValue_2->setText("0");
    ui->dexValue_2->setText("0");
    ui->conValue_2->setText("0");
    ui->intValue_2->setText("0");
    ui->wisValue_2->setText("0");
    ui->chaValue_2->setText("0");
    currStr = 0;
    currDex = 0;
    currCon = 0;
    currInt = 0;
    currWis = 0;
    currCha = 0;
}

void CharCreator::on_actionE_xit_triggered()
{
    this->close();
}

void CharCreator::on_action_Open_triggered()
{
    // If user has edited character info
    if (ui->nameValue->text() != "" || ui->levelValue->text().toInt() > 1 || rollClicked == true) {
        // Display warning about unsaved info
        QMessageBox::StandardButton warn = QMessageBox::warning(this, "Save Character?", "Do you want to save the changes you have made to the current character?", QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel, QMessageBox::Yes);
        if (warn == QMessageBox::Yes) {
            if (!on_action_Save_triggered()) {
                return;
            }
            setupDefaults();
            rollClicked = true;
            ui->levelButton->setEnabled(true);
        }
        else if (warn == QMessageBox::Cancel) {
            return;
        }
        else if (warn == QMessageBox::No) {
            setupDefaults();
            rollClicked = true;
            ui->levelButton->setEnabled(true);
        }
    }
    else {
        setupDefaults();
        rollClicked = true;
        ui->levelButton->setEnabled(true);
    }
    QString charName = QFileDialog::getOpenFileName(this, tr("Open Character"), "/characters", tr("CHARACTER Files (*.dcchar)"));
    std::string fileName = charName.toStdString();
    c->loadCharacter(fileName);
    updateGUI();
    ui->levelButton->setEnabled(true);
}

bool CharCreator::on_action_Save_triggered()
{
    if (ui->nameValue->text() == "") {
        QMessageBox::StandardButton err = QMessageBox::critical(this, "Invalid Character!", "This character is not valid. Please enter a name for your character.", QMessageBox::Ok);
        return false;
    }
    else if (rollClicked != true) {
        QMessageBox::StandardButton err = QMessageBox::critical(this, "Invalid Character!", "This character is not valid. Please click the roll button to generate the character\'s stats.", QMessageBox::Ok);
        return false;
    }
    QString charName = QFileDialog::getSaveFileName(this, tr("Save Character"), "/characters", tr("CHARACTER Files (*.dcchar)"));
    std::string fileName = charName.toStdString();
    c->name = ui->nameValue->text().toStdString();
    c->picture = selectImage;
    c->saveCharacter(fileName);
    return true;
}

void CharCreator::on_action_New_triggered()
{
    // If user has edited character info
    if (ui->nameValue->text() != "" || ui->levelValue->text().toInt() > 1 || rollClicked == true) {
        // Display warning about unsaved info
        QMessageBox::StandardButton warn = QMessageBox::warning(this, "Save Character?", "Do you want to save the changes you have made to the current character?", QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel, QMessageBox::Yes);
        if (warn == QMessageBox::Yes) {
            if (!on_action_Save_triggered()) {
                return;
            }
            c = new Fighter();
            setupDefaults();
        }
        else if (warn == QMessageBox::Cancel) {
            return;
        }
        else if (warn == QMessageBox::No) {
            c = new Fighter();
            setupDefaults();
        }
    }
}

void CharCreator::change_selected()
{
    ui->sprite1->setStyleSheet("border: none");
    ui->sprite2->setStyleSheet("border: none");
    ui->sprite3->setStyleSheet("border: none");
    ui->sprite4->setStyleSheet("border: none");
    ui->sprite5->setStyleSheet("border: none");
    if (QObject::sender()->objectName() == ui->sprite1->objectName()) {
        ui->sprite1->setStyleSheet("border: 2px solid red");
        selectImage = 1;
    }
    else if (QObject::sender()->objectName() == ui->sprite2->objectName()) {
        ui->sprite2->setStyleSheet("border: 2px solid red");
        selectImage = 2;
    }
    else if (QObject::sender()->objectName() == ui->sprite3->objectName()) {
        ui->sprite3->setStyleSheet("border: 2px solid red");
        selectImage = 3;
    }
    else if (QObject::sender()->objectName() == ui->sprite4->objectName()) {
        ui->sprite4->setStyleSheet("border: 2px solid red");
        selectImage = 4;
    }
    else if (QObject::sender()->objectName() == ui->sprite5->objectName()) {
        ui->sprite5->setStyleSheet("border: 2px solid red");
        selectImage = 5;
    }
}

void CharCreator::closeEvent(QCloseEvent *event)
{
    // If user has edited character info
    if (ui->nameValue->text() != "" || ui->levelValue->text().toInt() > 1 || rollClicked == true) {
        // Display warning about unsaved info
        QMessageBox::StandardButton warn = QMessageBox::warning(this, "Save Character?", "Do you want to save the changes you have made to the current character?", QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel, QMessageBox::Yes);
        if (warn == QMessageBox::Yes) {
            if (!on_action_Save_triggered()) {
                event->ignore();
                return;
            }
            this->sp->show();
            event->accept();
        }
        else if (warn == QMessageBox::Cancel) {
            event->ignore();
        }
        else if (warn == QMessageBox::No) {
            this->sp->show();
            event->accept();
        }
    }
    else {
        this->sp->show();
        event->accept();
    }
}

void CharCreator::on_rollButton_clicked()
{
    if (ui->nameValue->text() != "")
        c->name = ui->nameValue->text().toStdString();
    c->picture = selectImage;
    c->baseStr = c->generateAbilityScore();
    c->baseDex = c->generateAbilityScore();
    c->baseCon = c->generateAbilityScore();
    c->baseInt = c->generateAbilityScore();
    c->baseWis = c->generateAbilityScore();
    c->baseCha = c->generateAbilityScore();
    c->recalculateAttributes();
    rollClicked = true;
    ui->levelButton->setEnabled(true);
    updateGUI();
}

void CharCreator::updateGUI()
{
    ui->nameValue->setText(QString::fromStdString(c->name));
    selectImage = c->picture;
    setPicture();
    ui->strValue->setText(QString::fromStdString(std::to_string(c->baseStr)));
    ui->dexValue->setText(QString::fromStdString(std::to_string(c->baseDex)));
    ui->conValue->setText(QString::fromStdString(std::to_string(c->baseCon)));
    ui->intValue->setText(QString::fromStdString(std::to_string(c->baseInt)));
    ui->wisValue->setText(QString::fromStdString(std::to_string(c->baseWis)));
    ui->chaValue->setText(QString::fromStdString(std::to_string(c->baseCha)));
    ui->strValue_2->setText(QString::fromStdString(std::to_string(c->modStr)));
    ui->dexValue_2->setText(QString::fromStdString(std::to_string(c->modDex)));
    ui->conValue_2->setText(QString::fromStdString(std::to_string(c->modCon)));
    ui->intValue_2->setText(QString::fromStdString(std::to_string(c->modInt)));
    ui->wisValue_2->setText(QString::fromStdString(std::to_string(c->modWis)));
    ui->chaValue_2->setText(QString::fromStdString(std::to_string(c->modCha)));

    ui->levelValue->setText(QString::fromStdString(std::to_string(c->level)));
    ui->maxHPValue->setText(QString::fromStdString(std::to_string(c->maxHP)));
    std::string bonus = "";
    for (size_t i = 0; i < c->baseAttackBonus.size() - 1; i++)
    {
        bonus += std::to_string(c->baseAttackBonus[i]) + "/";
    }
    bonus += std::to_string(c->baseAttackBonus[c->baseAttackBonus.size() - 1]);
    ui->atkbonusValue->setText(QString::fromStdString(bonus));
}

void CharCreator::on_levelButton_clicked()
{
    c->levelUp();
    updateGUI();
}

void CharCreator::setPicture()
{
    ui->sprite1->setStyleSheet("border: none");
    ui->sprite2->setStyleSheet("border: none");
    ui->sprite3->setStyleSheet("border: none");
    ui->sprite4->setStyleSheet("border: none");
    ui->sprite5->setStyleSheet("border: none");

    if (selectImage == 1)
        ui->sprite1->setStyleSheet("border: 2px solid red");
    if (selectImage == 2)
        ui->sprite2->setStyleSheet("border: 2px solid red");
    if (selectImage == 3)
        ui->sprite3->setStyleSheet("border: 2px solid red");
    if (selectImage == 4)
        ui->sprite4->setStyleSheet("border: 2px solid red");
    if (selectImage == 5)
        ui->sprite5->setStyleSheet("border: 2px solid red");

}

void CharCreator::buildTemplate()
{
    FighterDirector fd;
    if (ui->templateCombo->currentIndex() != 0) {
        if (ui->templateCombo->currentIndex() == 1) {
            fd.setFighterBuilder(new BullyFighterBuilder);
        }

        if (ui->templateCombo->currentIndex() == 2) {
            fd.setFighterBuilder(new NimbleFighterBuilder);
        }

        if (ui->templateCombo->currentIndex() == 3) {
            fd.setFighterBuilder(new TankFighterBuilder);
        }
        fd.constructFighter();
        c = fd.getFighter();

        if (ui->nameValue->text() != "")
            c->name = ui->nameValue->text().toStdString();
        c->picture = selectImage;
        rollClicked = true;
        ui->levelButton->setEnabled(true);
        updateGUI();
    }
}
