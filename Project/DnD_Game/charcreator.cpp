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

CharCreator::CharCreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CharCreator)
{
    ui->setupUi(this);
    ui->templateCombo->addItem("None");
    ui->strValue->setReadOnly(true);
    ui->dexValue->setReadOnly(true);
    ui->conValue->setReadOnly(true);
    ui->intValue->setReadOnly(true);
    ui->wisValue->setReadOnly(true);
    ui->chaValue->setReadOnly(true);
    ui->strValue_2->setReadOnly(true);
    ui->dexValue_2->setReadOnly(true);
    ui->conValue_2->setReadOnly(true);
    ui->intValue_2->setReadOnly(true);
    ui->wisValue_2->setReadOnly(true);
    ui->chaValue_2->setReadOnly(true);
    setupDefaults();
    // Connect options to click signal
    connect(ui->sprite1, SIGNAL(clicked()), this, SLOT(change_selected()));
    connect(ui->sprite2, SIGNAL(clicked()), this, SLOT(change_selected()));
    connect(ui->sprite3, SIGNAL(clicked()), this, SLOT(change_selected()));
    connect(ui->sprite4, SIGNAL(clicked()), this, SLOT(change_selected()));
    connect(ui->sprite5, SIGNAL(clicked()), this, SLOT(change_selected()));
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
    selectImage = 1;
    ui->nameValue->setText("");
    ui->levelValue->setValue(1);
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
    if (ui->nameValue->text() != "" || ui->levelValue->value() > 1 || rollClicked == true) {
        // Display warning about unsaved info
        QMessageBox::StandardButton warn = QMessageBox::warning(this, "Save Character?", "Do you want to save the changes you have made to the current character?", QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel, QMessageBox::Yes);
        if (warn == QMessageBox::Yes) {
            if (!on_action_Save_triggered()) {
                return;
            }
            setupDefaults();
        }
        else if (warn == QMessageBox::Cancel) {
            return;
        }
        else if (warn == QMessageBox::No) {
            setupDefaults();
        }
    }
    else {
        setupDefaults();
    }
    QString charName = QFileDialog::getOpenFileName(this, tr("Open Character"), "C:/Users/chris/Documents/Visual Studio 2012/Projects/DnD_Game/characters", tr("CHARACTER Files (*.dcchar)"));
    std::string fileName = charName.toStdString();
    std::ifstream f(fileName, std::ios::in);
    if (f.is_open())
    {

        f.close();
    }
}

bool CharCreator::on_action_Save_triggered()
{
    if (ui->nameValue->text() == "") {
        QMessageBox::StandardButton err = QMessageBox::critical(this, "Invalid Character!", "This character is not valid. Please enter a name for your character.", QMessageBox::Ok);
        return false;
    }
    else if (rollClicked == false) {
        QMessageBox::StandardButton err = QMessageBox::critical(this, "Invalid Character!", "This character is not valid. Please click the roll button to generate the character\'s stats.", QMessageBox::Ok);
        return false;
    }
    QString charName = QFileDialog::getSaveFileName(this, tr("Save Character"), "C:/Users/chris/Documents/Visual Studio 2012/Projects/DnD_Game/characters", tr("CHARACTER Files (*.dcchar)"));
    std::string fileName = charName.toStdString();
    std::ofstream f(fileName, std::ios::out);
    if (f.is_open())
    {

        f.close();
    }
    else {
        return false;
    }
    return true;
}

void CharCreator::on_action_New_triggered()
{
    // If user has edited character info
    if (ui->nameValue->text() != "" || ui->levelValue->value() > 1 || rollClicked == true) {
        // Display warning about unsaved info
        QMessageBox::StandardButton warn = QMessageBox::warning(this, "Save Character?", "Do you want to save the changes you have made to the current character?", QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel, QMessageBox::Yes);
        if (warn == QMessageBox::Yes) {
            if (!on_action_Save_triggered()) {
                return;
            }
            setupDefaults();
        }
        else if (warn == QMessageBox::Cancel) {
            return;
        }
        else if (warn == QMessageBox::No) {
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
    if (ui->nameValue->text() != "" || ui->levelValue->value() > 1 || rollClicked == true) {
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
    rollClicked = true;
}
