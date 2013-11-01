#ifndef SPLASHDIALOG_H
#define SPLASHDIALOG_H

#include <QDialog>
#include "mainwindow.h"

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
    void on_loadButton_clicked();

private:
    Ui::SplashDialog *ui;
    MainWindow *w;
};

#endif // SPLASHDIALOG_H
