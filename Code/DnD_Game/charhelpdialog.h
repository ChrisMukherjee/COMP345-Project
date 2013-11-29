#ifndef CHARHELPDIALOG_H
#define CHARHELPDIALOG_H

#include <QDialog>

namespace Ui {
class CharHelpDialog;
}

class CharHelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CharHelpDialog(QWidget *parent = 0);
    ~CharHelpDialog();

private slots:
    void on_okButton_clicked();

private:
    Ui::CharHelpDialog *ui;
};

#endif // CHARHELPDIALOG_H
