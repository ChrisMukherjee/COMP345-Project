#ifndef CHARCREATOR_H
#define CHARCREATOR_H

#include <QMainWindow>

namespace Ui {
class CharCreator;
}

class CharCreator : public QMainWindow
{
    Q_OBJECT

public:
    explicit CharCreator(QWidget *parent = 0);
    ~CharCreator();

private:
    Ui::CharCreator *ui;
};

#endif // CHARCREATOR_H
