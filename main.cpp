//#include "sktcmasys.h"
#include "skttraymenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
    SktCmaSys w;
    w.SktInitCmaSys();
    w.show();
    */
    SktTrayMenu w;
    w.SktInitTrayMenu();
    w.SktShowTrayMenu();
    w.SktShowMainWindow();
    return a.exec();
}
