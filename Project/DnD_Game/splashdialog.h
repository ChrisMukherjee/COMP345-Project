#ifndef SPLASHDIALOG_H
#define SPLASHDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "mapcreator.h"

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

    void on_newButton_clicked();

private:
    Ui::SplashDialog *ui;
    MainWindow *w;
    MapCreator *m;
};

#endif // SPLASHDIALOG_H
