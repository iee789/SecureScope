#include "sktcmasys.h"
#include "ui_sktcmasys.h"

#include <QEvent>
#include <QPainter>
#include <QPalette>
#include <QBitmap>
#include <QAction>
#include <QLineEdit>
#include <QTreeWidget>
#include <QTreeWidgetItem>

SktCmaSys::SktCmaSys(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SktCmaSys)
{
    ui->setupUi(this);
}

SktCmaSys::~SktCmaSys()
{
    delete ui;
}

void SktCmaSys::SktInitCmaSys()
{
    QEvent *event=new QEvent(QEvent::Resize);
    ui->topWdt->installEventFilter(this);//安装事件过滤器
    this->eventFilter(ui->topWdt,event);

    setWindowFlags(Qt::FramelessWindowHint);//去掉边框
    //setAttribute(Qt::WA_TranslucentBackground);//设置透明，去掉小三角
    m_oQPixmap.load(":/SktPicPath/bk.png");
    resize(m_oQPixmap.size());
    setMask(m_oQPixmap.mask());

    //ui->consoleWdt->setStyleSheet("background-color:#525252;");//增加背景色
    ui->couldWdt->setStyleSheet("background-color:#696969;");//增加背景色

    SktSetBtnStyle(ui->closeBtn,
                   ":/SktPicPath/icon_closez.png",
                   ":/SktPicPath/icon_closeh.png",
                   ":/SktPicPath/icon_close.png");
    SktSetBtnStyle(ui->maxBtn,
                   ":/SktPicPath/icon_downz.png",
                   ":/SktPicPath/icon_downh.png",
                   ":/SktPicPath/icon_down.png");
    SktSetBtnStyle(ui->minBtn,
                   ":/SktPicPath/icon_smallz.png",
                   ":/SktPicPath/icon_smallh.png",
                   ":/SktPicPath/icon_small.png");

    SktSetBtnStyle(ui->indexBtn,
                   ":/SktPicPath/button_bg.png",
                   ":/SktPicPath/button_bg.png",
                   ":/SktPicPath/button_bg.png");
    SktSetBtnStyle(ui->videoBtn,
                   ":/SktPicPath/button_bg.png",
                   ":/SktPicPath/button_bg.png",
                   ":/SktPicPath/button_bg.png");
    //左边的9个按钮
    SktSetBtnStyle(ui->picBtn,
                   ":/SktPicPath/cma_03-07.png",
                   ":/SktPicPath/cma_03-07-.png",
                   ":/SktPicPath/cma_03-07.png");
    SktSetBtnStyle(ui->b1Btn,
                   ":/SktPicPath/cma_03-24.png",
                   ":/SktPicPath/cma_03-24.png",
                   ":/SktPicPath/cma_03-24-.png");
    SktSetBtnStyle(ui->b2Btn,
                   ":/SktPicPath/cma_03-23.png",
                   ":/SktPicPath/cma_03-23-.png",
                   ":/SktPicPath/cma_03-23.png");
    SktSetBtnStyle(ui->b3Btn,
                   ":/SktPicPath/cma_03-09.png",
                   ":/SktPicPath/cma_03-09-.png",
                   ":/SktPicPath/cma_03-09.png");
    SktSetBtnStyle(ui->b4Btn,
                   ":/SktPicPath/cma_03-22.png",
                   ":/SktPicPath/cma_03-22-.png",
                   ":/SktPicPath/cma_03-22.png");
    SktSetBtnStyle(ui->b5Btn,
                   ":/SktPicPath/cma_03-17.png",
                   ":/SktPicPath/cma_03-17-.png",
                   ":/SktPicPath/cma_03-17.png");
    SktSetBtnStyle(ui->b6Btn,
                   ":/SktPicPath/cma_03-16.png",
                   ":/SktPicPath/cma_03-16-.png",
                   ":/SktPicPath/cma_03-16.png");
    SktSetBtnStyle(ui->b7Btn,
                   ":/SktPicPath/cma_03-09.png",
                   ":/SktPicPath/cma_03-09-.png",
                   ":/SktPicPath/cma_03-09.png");
    SktSetBtnStyle(ui->b8Btn,
                   ":/SktPicPath/cma_03-18.png",
                   ":/SktPicPath/cma_03-1-8.png",
                   ":/SktPicPath/cma_03-18.png");
    /*
    SktSetBtnStyle(ui->devBtn,
                   ":/SktPicPath/shezhi.png",
                   ":/SktPicPath/down2.png",
                   ":/SktPicPath/shezhi.png");
    SktSetBtnStyle(ui->addBtn,
                   ":/SktPicPath/add.png",
                   ":/SktPicPath/add2.png",
                   ":/SktPicPath/add.png");
    */
    SktSetBtnStyle(ui->srn1Btn,
                   ":/SktPicPath/icon_01h.png",
                   ":/SktPicPath/icon_01.png",
                   ":/SktPicPath/icon_01h.png");
    SktSetBtnStyle(ui->srn4Btn,
                   ":/SktPicPath/icon_02h.png",
                   ":/SktPicPath/icon_02.png",
                   ":/SktPicPath/icon_02h.png");
    SktSetBtnStyle(ui->srn9Btn,
                   ":/SktPicPath/icon_03h.png",
                   ":/SktPicPath/icon_03.png",
                   ":/SktPicPath/icon_03h.png");
    SktSetBtnStyle(ui->srn16Btn,
                   ":/SktPicPath/icon_04h.png",
                   ":/SktPicPath/icon_04.png",
                   ":/SktPicPath/icon_04h.png");
    SktSetBtnStyle(ui->fullBtn,
                   ":/SktPicPath/icon_maxh.png",
                   ":/SktPicPath/icon_max.png",
                   ":/SktPicPath/icon_maxh.png");
    SktSetBtnStyle(ui->realBtn,
                   "",
                   ":/SktPicPath/pic_02h.png",
                   ":/SktPicPath/icon_01h.png");
    SktSetBtnStyle(ui->htyBtn,
                   "",
                   ":/SktPicPath/pic_02h.png",
                   ":/SktPicPath/icon_01h.png");
    SktSetBtnStyle(ui->stopBtn,
                   ":/SktPicPath/2d12.png",
                   ":/SktPicPath/2d11.png",
                   ":/SktPicPath/2d12.png");
    //音量图标
    SktSetBtnStyle(ui->volbtn1,
                   ":/SktPicPath/102.png",
                   ":/SktPicPath/icon_speaker.png",
                   ":/SktPicPath/102.png");


    SktLoadQssFile(":/SktQssFilePath/SktQssFile.css");
    ui->logoLbl->setPixmap(QPixmap(":/SktPicPath/logo.png"));
    SktSetWdtBack(ui->topWdt,":/SktPicPath/top.png");
    SktSetWdtBack(ui->consoleWdt,":/SktPicPath/11-1_03.png");

    SktSetSignal();

    QAction *searchAction=new QAction(ui->findEdt);
    searchAction->setIcon(QIcon(":/SktPicPath/icon_Load .png"));
    ui->findEdt->addAction(searchAction,QLineEdit::TrailingPosition);
    SktAddCmaList();

    //初始化16分屏
    m_pLabel[0]=ui->lb1;
    m_pLabel[0]->installEventFilter(this);
    m_pLabel[1]=ui->lb2;
    m_pLabel[1]->installEventFilter(this);
    m_pLabel[2]=ui->lb3;
    m_pLabel[2]->installEventFilter(this);
    m_pLabel[3]=ui->lb4;
    m_pLabel[3]->installEventFilter(this);
    m_pLabel[4]=ui->lb5;
    m_pLabel[4]->installEventFilter(this);
    m_pLabel[5]=ui->lb6;
    m_pLabel[5]->installEventFilter(this);
    m_pLabel[6]=ui->lb7;
    m_pLabel[6]->installEventFilter(this);
    m_pLabel[7]=ui->lb8;
    m_pLabel[7]->installEventFilter(this);
    m_pLabel[8]=ui->lb9;
    m_pLabel[8]->installEventFilter(this);
    m_pLabel[9]=ui->lb10;
    m_pLabel[9]->installEventFilter(this);
    m_pLabel[10]=ui->lb11;
    m_pLabel[10]->installEventFilter(this);
    m_pLabel[11]=ui->lb12;
    m_pLabel[11]->installEventFilter(this);
    m_pLabel[12]=ui->lb13;
    m_pLabel[12]->installEventFilter(this);
    m_pLabel[13]=ui->lb14;
    m_pLabel[13]->installEventFilter(this);
    m_pLabel[14]=ui->lb15;
    m_pLabel[14]->installEventFilter(this);
    m_pLabel[15]=ui->lb16;
    m_pLabel[15]->installEventFilter(this);
    SktInitAllLbl();

    SktInitMediaPlayer();
//    m_oTrayMenu.SktInitTrayMenu();
//    m_oTrayMenu.SktShowTrayMenu();
}

void SktCmaSys::SktSetSignal()
{
    connect(ui->closeBtn,&QPushButton::clicked,this,&SktCmaSys::SktCloseBtnSlots);
    connect(ui->maxBtn,&QPushButton::clicked,this,&SktCmaSys::SktMaxBtnSlots);
    connect(ui->minBtn,&QPushButton::clicked,this,&SktCmaSys::SktMinBtnSlots);
    connect(ui->indexBtn,&QPushButton::clicked,this,&SktCmaSys::SktIndexBtnSlots);
    connect(ui->videoBtn,&QPushButton::clicked,this,&SktCmaSys::SktVideoBtnSlots);

    connect(ui->cmaListWdt,&QTreeWidget::itemClicked,this,&SktCmaSys::SktCmaTreeWdtSlot);

    connect(ui->fullBtn,&QPushButton::clicked,this,&SktCmaSys::SktFullBtnSlots);

    connect(ui->srn1Btn,&QPushButton::clicked,this,&SktCmaSys::SktShowScreen1);
    connect(ui->srn4Btn,&QPushButton::clicked,this,&SktCmaSys::SktShowScreen4);
    connect(ui->srn9Btn,&QPushButton::clicked,this,&SktCmaSys::SktShowScreen9);
    connect(ui->srn16Btn,&QPushButton::clicked,this,&SktCmaSys::SktShowScreen16);

    connect(ui->stopBtn,&QPushButton::clicked,this,&SktCmaSys::SktStopBtnSlots);
    connect(ui->volSdr,&QSlider::valueChanged,this,&SktCmaSys::SktVolSdrSlots);
}

void SktCmaSys::SktAddCmaList()
{
    QTreeWidgetItem *itemRoot=new QTreeWidgetItem(ui->cmaListWdt,QStringList(QString("测试监控")));
    itemRoot->setIcon(0,QIcon(":/SktPicPath/1.png"));

    SktAddSubItem(itemRoot,"192.168.1.100",":/SktPicPath/3.png");
    SktAddSubItem(itemRoot,"192.168.1.101",":/SktPicPath/3.png");
    SktAddSubItem(itemRoot,"192.168.1.102",":/SktPicPath/3.png");
    SktAddSubItem(itemRoot,"192.168.1.103",":/SktPicPath/3.png");

    QTreeWidgetItem *itemRoot2=new QTreeWidgetItem(ui->cmaListWdt,QStringList(QString("正式上线")));
    itemRoot2->setIcon(0,QIcon(":/SktPicPath/1.png"));

    SktAddSubItem(itemRoot2,"192.168.1.1",":/SktPicPath/3.png");
    SktAddSubItem(itemRoot2,"192.168.1.12",":/SktPicPath/3.png");
    SktAddSubItem(itemRoot2,"192.168.1.13",":/SktPicPath/3.png");
    SktAddSubItem(itemRoot2,"192.168.1.113",":/SktPicPath/3.png");
    SktAddSubItem(itemRoot2,"192.168.1.13",":/SktPicPath/3.png");
}

void SktCmaSys::SktInitAllLbl()
{
    //添加背景图
    for(int i=0;i<16;i++)
    {
        m_pLabel[i]->setStyleSheet("background-color: #B8B7B7");
    }
}

void SktCmaSys::SktSetCurLblMax()
{
    for(int i=0;i<16;i++)
    {
        m_pLabel[i]->setVisible(false);
    }

    if(true==m_bIsMax)
    {
        for(int i=0;i<16;i++)
        {
            m_pLabel[i]->setVisible(true);
        }
        m_bIsMax=false;
    }
    else
    {
        m_pCurLbl->setVisible(true);
        m_bIsMax=true;
    }
}

void SktCmaSys::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),m_oQPixmap);
}

void SktCmaSys::mousePressEvent(QMouseEvent *event)
{
    //记录坐标
    if(event->button()==Qt::LeftButton)
    {
        m_oQPoint=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
}

void SktCmaSys::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&&Qt::LeftButton)
    {
        QPoint oGlobalPoint=event->globalPos();
        QPoint oMovePoint=oGlobalPoint-m_oQPoint;
        move(oMovePoint);
        event->accept();
    }
}

bool SktCmaSys::eventFilter(QObject *watched, QEvent *event)
{
    QMouseEvent *pMouseEvent=static_cast<QMouseEvent*>(event);
    if(event->type()==QEvent::Resize)
    {
        SktSetWdtBack(ui->topWdt,":/SktPicPath/top.png");
    }

    if(event->type()==QEvent::MouseButtonDblClick&&
            (pMouseEvent->buttons()==Qt::LeftButton))
    {
        SktSetCurLblMax();
    }

    if(event->type()==QEvent::MouseButtonPress)
    {
        QMouseEvent *pMouseEvent=static_cast<QMouseEvent*>(event);
        if(pMouseEvent->buttons()==Qt::LeftButton)
        {
            m_pCurLbl=qobject_cast<QLabel*>(watched);
            if(!m_pCurLbl)
                return QObject::eventFilter(watched,event);
            SktInitAllLbl();
            m_pCurLbl->setFocus();
            m_pCurLbl->setStyleSheet("background-color: #FFF");
        }
    }

    return QObject::eventFilter(watched,event);
}

void SktCmaSys::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    //esc键退出全屏
    case Qt::Key_Escape:
    {
        ui->topWdt->setVisible(true);
        ui->leftWdt->setVisible(true);
        ui->rightTopWdt->setVisible(true);
        ui->rightDownWdt->setVisible(true);
        setWindowState(Qt::WindowMaximized);
        break;
    }
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}

void SktCmaSys::SktCloseBtnSlots()
{
    QApplication::exit();
}

void SktCmaSys::SktMaxBtnSlots()
{
    if(isMaximized())
    {
        showNormal();
    }
    else
    {
        setWindowState(Qt::WindowMaximized);
    }
}

void SktCmaSys::SktMinBtnSlots()
{
    showMinimized();
}

void SktCmaSys::SktIndexBtnSlots()
{
    ui->indexBtn->setIcon(QIcon(":/SktPicPath/icon_homeh.png"));
    ui->videoBtn->setIcon(QIcon(":/SktPicPath/icon_jiankong .png"));

    ui->SktStackWdt->setCurrentWidget(ui->p1);
}

void SktCmaSys::SktVideoBtnSlots()
{
    ui->indexBtn->setIcon(QIcon(":/SktPicPath/icon_home.png"));
    ui->videoBtn->setIcon(QIcon(":/SktPicPath/icon_jiankong h.png"));

    ui->SktStackWdt->setCurrentWidget(ui->p2);
}

void SktCmaSys::SktFullBtnSlots()
{
    ui->topWdt->setVisible(false);
    ui->leftWdt->setVisible(false);
    ui->rightTopWdt->setVisible(false);
    ui->rightDownWdt->setVisible(false);
    showFullScreen();
}

void SktCmaSys::SktShowScreen1()
{
    for(int i=0;i<16;i++)
    {
        m_pLabel[i]->setVisible(false);
    }
    m_pLabel[0]->setVisible(true);
}

void SktCmaSys::SktShowScreen4()
{
    for(int i=0;i<16;i++)
    {
        m_pLabel[i]->setVisible(false);
    }
    //显示4宫格
    m_pLabel[0]->setVisible(true);
    m_pLabel[1]->setVisible(true);
    m_pLabel[4]->setVisible(true);
    m_pLabel[5]->setVisible(true);
}
void SktCmaSys::SktShowScreen9()
{
    for(int i=0;i<16;i++)
    {
        m_pLabel[i]->setVisible(false);
    }
    for(int k=0;k<9;k++)
    {
        m_pLabel[k]->setVisible(true);
    }
}

void SktCmaSys::SktShowScreen16()
{
    for(int i=0;i<16;i++)
    {
        m_pLabel[i]->setVisible(true);
    }
}

void SktCmaSys::SktStopBtnSlots()
{
    HWND handle=(HWND)m_pCurLbl->winId();
    if(!handle)
    {
        return ;
    }

    SktStopVideo(handle);
}

void SktCmaSys::SktVolSdrSlots(int value)
{
    SktSetCurVolume(value);
}

void SktCmaSys::SktCmaTreeWdtSlot(QTreeWidgetItem *pSubTree, int k)
{
    QTreeWidgetItem *pRootTree=pSubTree->parent();
    if(!pRootTree)
        return;

    QString qsRoot=pRootTree->text(k);
    QString strIp=pSubTree->text(k);

    if(!m_pCurLbl)
        return ;

    HWND handle=(HWND)m_pCurLbl->winId();
    if(!handle)
        return;

    SktPlayVideo(strIp.toLocal8Bit().data(),handle);
}

void SktCmaSys::SktAddSubItem(QTreeWidgetItem *pRootItem, const char *pstIp, const char *pstPicPath)
{
    QTreeWidgetItem *SubItem=new QTreeWidgetItem(pRootItem,QStringList(QString::fromLocal8Bit(pstIp)));
    SubItem->setIcon(0,QIcon(pstPicPath));
    pRootItem->addChild(SubItem);
    ui->cmaListWdt->expandAll();
}

