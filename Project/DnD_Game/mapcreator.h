#ifndef MAPCREATOR_H
#define MAPCREATOR_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include "splashdialog.h"
#include "ClickLabel.h"
#include <QWidget>
#include <QList>

namespace Ui {
class MapCreator;
}

class MapCreator : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapCreator(QWidget *parent = 0);
    ~MapCreator();
    void populateMap(int w, int h);
    void addCells();
    bool setWall(int x, int y);
    bool setStart(int x, int y);
    bool setEnd(int x, int y);
    bool setChest(int x, int y);
    bool setMonster(int x, int y);
    bool setEmpty(int x, int y);
    void setupDefaults();
    void deleteMap();
    bool validateMap();
    void closeEvent(QCloseEvent *event);
    SplashDialog *sp;

private slots:
    void on_action_Open_triggered();

    void on_actionE_xit_triggered();

    bool on_action_Save_triggered();

    void on_goButton_clicked();

    void on_action_Help_triggered();

    void map_label_clicked();

    void change_selected();

    void on_action_New_triggered();

private:
    Ui::MapCreator *ui;
    int height, width;
    char selectType;
    int startX, startY, endX, endY;
    ClickLabel*** map;
    char** mapChars;
    int numMonsters;
};

#endif // MAPCREATOR_H
