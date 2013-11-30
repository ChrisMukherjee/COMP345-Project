#ifndef SPLASHDIALOG_H
#define SPLASHDIALOG_H

#include <QDialog>

namespace Ui {
class SplashDialog;
}

class SplashDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SplashDialog(QWidget *parent = 0);
    ~SplashDialog();

private slots:
    void on_newButton_clicked();

    void on_mapButton_clicked();

    void on_characterButton_clicked();

    void on_quitButton_clicked();

private:
    Ui::SplashDialog *ui;
};

#endif // SPLASHDIALOG_H
