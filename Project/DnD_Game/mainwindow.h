#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "splashdialog.h"

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
    SplashDialog *sp;

private slots:
    void on_actionE_xit_triggered();

    void on_action_New_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
