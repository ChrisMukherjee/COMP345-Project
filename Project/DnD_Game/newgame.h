#ifndef NEWGAME_H
#define NEWGAME_H

#include <QDialog>
#include "mainwindow.h"
#include <QList>
#include <QListWidgetItem>

namespace Ui {
class NewGame;
}

class NewGame : public QDialog
{
    Q_OBJECT

public:
    explicit NewGame(QWidget *parent = 0);
    ~NewGame();
    void populate_lists();
    MainWindow *mw;

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::NewGame *ui;

public:
    QList<QListWidgetItem*> selectedChar;
    QList<QListWidgetItem*> selectedMap;
};

#endif // NEWGAME_H
