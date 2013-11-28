#ifndef CHARCREATOR_H
#define CHARCREATOR_H

#include <QMainWindow>
#include "splashdialog.h"
#include "clicklabel.h"
#include "Fighter.h"

namespace Ui {
class CharCreator;
}

class CharCreator : public QMainWindow
{
    Q_OBJECT

public:
    explicit CharCreator(QWidget *parent = 0);
    ~CharCreator();
    void setupDefaults();
    void closeEvent(QCloseEvent *event);
    void setPicture();
    SplashDialog *sp;

private slots:
    void on_action_Open_triggered();

    void on_actionE_xit_triggered();

    bool on_action_Save_triggered();

    void on_action_New_triggered();

    void change_selected();

    void on_rollButton_clicked();

    void updateGUI();

    void on_levelButton_clicked();

private:
    Ui::CharCreator *ui;
    Fighter* c;
    int selectImage;
    int currStr;
    int currDex;
    int currCon;
    int currInt;
    int currWis;
    int currCha;
    bool rollClicked;
};

#endif // CHARCREATOR_H
