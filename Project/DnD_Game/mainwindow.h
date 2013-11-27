#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "splashdialog.h"
#include <QString>
#include <QPixmap>
#include <QLabel>
#include "Character.h"
#include "Grid.h"

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
    void setMonsterPic();
    void setFighterPic();
    void playGame();

private slots:
    void on_actionE_xit_triggered();

    void on_action_New_triggered();

    void start();

private:
    Ui::MainWindow *ui;
    QLabel*** labelmap;
    Fighter* player;
    Grid* map;
    QPixmap playerSkin;
    QPixmap monsterSkin;
    QPixmap monsterdeadSkin;
};

#endif // MAINWINDOW_H
