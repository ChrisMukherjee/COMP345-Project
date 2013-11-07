#ifndef MAPCREATOR_H
#define MAPCREATOR_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
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

private slots:
    void on_action_Open_triggered();

    void on_actionE_xit_triggered();

    void on_action_Save_triggered();

    void on_goButton_clicked();

    void on_action_Help_triggered();

    void map_label_clicked();

    void change_selected();

private:
    Ui::MapCreator *ui;
    int height;
    int width;
    char selectType;
    int startPos, endPos;
    QList<ClickLabel*> map;
};

#endif // MAPCREATOR_H
