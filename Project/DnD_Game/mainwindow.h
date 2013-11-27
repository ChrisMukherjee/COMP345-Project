#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "splashdialog.h"
#include <QString>
#include <QPixmap>
#include <QLabel>
#include "Character.h"
#include "Grid.h"
#include <vector>
#include "InputManager.h"
#include "InputEvent.h"

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
    void displayStart();
    void displayMap();
    void setMonsterPic();
    void setFighterPic();
    void playGame();
    void playerTurn();
    void scale_images();
    void updateInvList();
    bool loaded;

private slots:
    void on_actionE_xit_triggered();

    void on_action_New_triggered();

    void start();

    void equip();

private:
    Ui::MainWindow *ui;
    QLabel*** labelmap;
    Fighter* player;
    Grid* map;
    QPixmap playerSkin;
    QPixmap monsterSkin;
    QPixmap monsterdeadSkin;
    QPixmap wallSkin;
    QPixmap mudSkin;
    QPixmap chestSkin;
    QPixmap chestemptySkin;
    QPixmap startSkin;
    QPixmap endSkin;
    QString mapFName;
    QString charFName;
    std::vector<InputEvent> events;
    bool dead;
};

#endif // MAINWINDOW_H
