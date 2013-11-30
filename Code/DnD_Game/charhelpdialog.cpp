#include "charhelpdialog.h"
#include "ui_charhelpdialog.h"

CharHelpDialog::CharHelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CharHelpDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
}

CharHelpDialog::~CharHelpDialog()
{
    delete ui;
}

void CharHelpDialog::on_okButton_clicked()
{
    this->close();
}
