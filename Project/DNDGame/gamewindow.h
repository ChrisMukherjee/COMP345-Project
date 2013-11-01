#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    explicit GameWindow(QWidget *parent = 0, int x = 1);
    ~GameWindow();
    void showEvent ( QShowEvent * /* evt */ );

private slots:
    void on_action_Exit_triggered();

    void on_action_Load_triggered();

    void on_action_Save_triggered();

private:
    Ui::GameWindow *ui;
    int load;
};

#endif // GAMEWINDOW_H
