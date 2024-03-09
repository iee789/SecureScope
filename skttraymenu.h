#ifndef SKTTRAYMENU_H
#define SKTTRAYMENU_H

#include <QMenu>
#include <QSystemTrayIcon>
#include <QApplication>

#include "sktcmasys.h"

class SktTrayMenu : public QMenu
{
public:
    SktTrayMenu();
    ~SktTrayMenu();

    void SktInitTrayMenu();
    void SktShowTrayMenu();
    void SktShowMainWindow();

private slots:
    void SktSysExit();
    void onActivated(QSystemTrayIcon::ActivationReason iSwitch);

private:
    QAction *m_pExit=nullptr;
    QAction *m_pAdd=nullptr;
    QAction *m_pAbout=nullptr;

    QSystemTrayIcon *m_pTrayIcon=nullptr;

    SktCmaSys m_oSktCmaSys;
};

#endif // SKTTRAYMENU_H
