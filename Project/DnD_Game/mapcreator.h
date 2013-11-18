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
    int height;
    int width;
    char selectType;
    int startPos, endPos;
    QList<ClickLabel*> map;
    QList<char> mapChars;
};

#endif // MAPCREATOR_H
