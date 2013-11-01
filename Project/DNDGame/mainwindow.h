#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_newButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::MainWindow *ui;
    GameWindow *w;
};

#endif // MAINWINDOW_H
