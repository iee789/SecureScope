#ifndef SKTCMASYS_H
#define SKTCMASYS_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPixmap>
#include <QPoint>
#include <QTreeWidget>
#include <QLabel>
#include <QKeyEvent>

#include "sktsetstyle.h"
#include "sktmediaplayer.h"
//#include "skttraymenu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SktCmaSys; }
QT_END_NAMESPACE

class SktCmaSys : public QMainWindow,public SktSetStyle,public SktMediaPlayer
{
    Q_OBJECT

public:
    SktCmaSys(QWidget *parent = nullptr);
    ~SktCmaSys();

    void SktInitCmaSys();
    void SktSetSignal();
    void SktAddCmaList();
    void SktInitAllLbl();
    void SktSetCurLblMax();

    virtual void paintEvent(QPaintEvent*);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual bool eventFilter(QObject *watched, QEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void SktCloseBtnSlots();
    void SktMaxBtnSlots();
    void SktMinBtnSlots();
    void SktIndexBtnSlots();
    void SktVideoBtnSlots();

    void SktFullBtnSlots();

    void SktShowScreen1();//展示1分屏
    void SktShowScreen4();//展示4分屏
    void SktShowScreen9();//展示9分屏
    void SktShowScreen16();//展示16分屏

    void SktStopBtnSlots();
    void SktVolSdrSlots(int value);

    void SktCmaTreeWdtSlot(QTreeWidgetItem *pSubTree,int k);
    void SktAddSubItem(QTreeWidgetItem *pRootItem,const char *pstIp,const char *pstPicPath);
private:
    Ui::SktCmaSys *ui;

    QPixmap m_oQPixmap;
    QPoint m_oQPoint;
//    SktTrayMenu m_oTrayMenu;

    QLabel *m_pLabel[16]={NULL};//16分屏
    QLabel *m_pCurLbl=NULL;

    bool m_bIsMax=false;//当前视频显示是否为最大化
};
#endif // SKTCMASYS_H
