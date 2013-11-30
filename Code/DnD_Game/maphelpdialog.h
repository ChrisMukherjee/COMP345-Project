#ifndef MAPHELPDIALOG_H
#define MAPHELPDIALOG_H

#include <QDialog>

namespace Ui {
class MapHelpDialog;
}

class MapHelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MapHelpDialog(QWidget *parent = 0);
    ~MapHelpDialog();

private slots:
    void on_okButton_clicked();

private:
    Ui::MapHelpDialog *ui;
};

#endif // MAPHELPDIALOG_H
