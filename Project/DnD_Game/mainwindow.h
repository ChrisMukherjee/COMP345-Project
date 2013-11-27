#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "splashdialog.h"
#include <QString>
#include <QPixmap>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);
    void populateMap(int w, int h);
    SplashDialog *sp;
    void setChar(QString charName);
    void setMap(QString mapName);
    void displayMap();
    QPixmap chooseMonster();
    QPixmap setFighterPic();
    void start();

private slots:
    void on_actionE_xit_triggered();

    void on_action_New_triggered();

private:
    Ui::MainWindow *ui;
    QLabel*** labelmap;
};

#endif // MAINWINDOW_H
