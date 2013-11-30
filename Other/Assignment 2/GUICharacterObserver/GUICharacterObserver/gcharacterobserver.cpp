#include "gcharacterobserver.h"
#include "ui_gcharacterobserver.h"

GCharacterObserver::GCharacterObserver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GCharacterObserver)
{
    ui->setupUi(this);
}

GCharacterObserver::~GCharacterObserver()
{
    delete ui;
    subject->detach(this);
    subject = NULL;
}

void GCharacterObserver::setSubject(Character &c)
{
    subject = &c;
    subject->attach(this);
}

void GCharacterObserver::update(Observable* o)
{
    if (subject == o)
    {
        //ui->lineEdit->setText(QString::fromStdString(subject->goldToString()));
        ui->nameField->setText(QString::fromStdString(subject->name));
        ui->levelField->setText(QString::number(subject->level));
        ui->strField->setText(QString::number(subject->effStr));
        ui->dexField->setText(QString::number(subject->effDex));
        ui->conField->setText(QString::number(subject->effCon));
        ui->intField->setText(QString::number(subject->effInt));
        ui->wisField->setText(QString::number(subject->effWis));
        ui->chaField->setText(QString::number(subject->effCha));
        ui->modStrField->setText(QString::number(subject->modStr));
        ui->modDexField->setText(QString::number(subject->modDex));
        ui->modConField->setText(QString::number(subject->modCon));
        ui->modIntField->setText(QString::number(subject->modInt));
        ui->modWisField->setText(QString::number(subject->modWis));
        ui->modChaField->setText(QString::number(subject->modCha));
        ui->invField->setText(QString::fromStdString(subject->invToString()));
    }
}
