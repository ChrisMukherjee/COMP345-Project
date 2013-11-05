#ifndef GCHARACTEROBSERVER_H
#define GCHARACTEROBSERVER_H

#include <QMainWindow>
#include "Observer.h"
#include "Character.h"
#include "Observable.h"

namespace Ui {
class GCharacterObserver;
}

class GCharacterObserver :
        public QMainWindow,
        public Observer
{
    Q_OBJECT

public:
    explicit GCharacterObserver(QWidget *parent = 0);
    ~GCharacterObserver();

    void setSubject(Character& c);
    void update(Observable* o);

private:
    Ui::GCharacterObserver *ui;
    Character* subject;
};

#endif // GCHARACTEROBSERVER_H
