#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(QWidget *parent = 0, char x = 'l');
    ~MainWindow();

private slots:
    void on_actionE_xit_triggered();

    void on_action_Load_triggered();

    void on_action_Save_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H