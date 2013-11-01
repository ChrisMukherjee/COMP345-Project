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

private:
    Ui::MapCreator *ui;
};

#endif // MAPCREATOR_H
