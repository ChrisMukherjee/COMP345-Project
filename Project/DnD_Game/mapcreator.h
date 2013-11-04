#ifndef MAPCREATOR_H
#define MAPCREATOR_H

#include <QMainWindow>

namespace Ui {
class MapCreator;
}

class MapCreator : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapCreator(QWidget *parent = 0);
    ~MapCreator();

private slots:
    void on_action_Open_triggered();

    void on_actionE_xit_triggered();

    void on_action_Save_triggered();

    void on_goButton_clicked();

private:
    Ui::MapCreator *ui;
};

#endif // MAPCREATOR_H
