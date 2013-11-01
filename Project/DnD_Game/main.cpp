#include "splashdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SplashDialog sp;
    sp.show();

    return a.exec();
}
