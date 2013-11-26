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
    QPixmap chooseMonster();
    void setupDefaults();
    bool move(char direction);
    void playGame();

private slots:
    void on_actionE_xit_triggered();

    void on_action_New_triggered();

private:
    Ui::MainWindow *ui;
    int height, width;
    int level;
    int startX, startY, endX, endY, playerX, playerY, tmpX, tmpY;
    QLabel*** map;
    char** mapChars;
    char onCell;
};

#endif // MAINWINDOW_H
