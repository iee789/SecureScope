#include "skttraymenu.h"

SktTrayMenu::SktTrayMenu()
{

}

SktTrayMenu::~SktTrayMenu()
{

}

void SktTrayMenu::SktInitTrayMenu()
{
    m_pExit = new QAction(QIcon(":/SktPicPath/1.ico"),QString("退出"),this);
    m_pAbout= new QAction(QIcon(":/SktPicPath/2.ico"),QString("关于我们"),this);
    m_pAdd = new QAction(QIcon(":/SktPicPath/3.ico"),QString("添加"),this);

    addAction(m_pExit);
    addAction(m_pAbout);
    addAction(m_pAdd);
    addSeparator();

    connect(m_pExit,&QAction::triggered,this,&SktTrayMenu::SktSysExit);
}

void SktTrayMenu::SktShowTrayMenu()
{
    m_pTrayIcon=new QSystemTrayIcon(this);
    m_pTrayIcon->setContextMenu(this);
    m_pTrayIcon->setToolTip(QString("监控系统-测试版本"));
    m_pTrayIcon->setIcon(QIcon(":/SktPicPath/skt.ico"));
    m_pTrayIcon->show();

    connect(m_pTrayIcon,&QSystemTrayIcon::activated,this,&SktTrayMenu::onActivated);
    m_pTrayIcon->show();
}

void SktTrayMenu::SktShowMainWindow()
{
    m_oSktCmaSys.SktInitCmaSys();
    m_oSktCmaSys.show();
}

void SktTrayMenu::SktSysExit()
{
    QApplication::exit();
//    close();
}

void SktTrayMenu::onActivated(QSystemTrayIcon::ActivationReason iSwitch)
{
    switch (iSwitch) {

    case QSystemTrayIcon::Trigger:
    {
        break;
    }
    case QSystemTrayIcon::DoubleClick:
    {
        //显示主界面
        m_oSktCmaSys.show();
        break;
    }
    default:
        break;
    }
}
