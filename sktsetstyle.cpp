#include "sktsetstyle.h"

SktSetStyle::SktSetStyle()
{

}

void SktSetStyle::SktSetBtnStyle(QPushButton *pBtn, QString n, QString h, QString p)
{
    QString strBtnStyle="QPushButton{border-image:url("+n+");}";//按钮正常显示时的图片
    strBtnStyle+="QPushButton:hover{border-image:url("+h+");}";//按钮高亮时的图片
    strBtnStyle+="QPushButton:pressed{border-image:url("+p+");}";//按钮按下时的图片

    pBtn->setStyleSheet(strBtnStyle);
}

void SktSetStyle::SktRadioBtnStyle(QRadioButton *pBtn, QString n, QString h, QString p)
{
    QString strBtnStyle="QRadioButton{border-image:url("+n+");}";//按钮正常显示时的图片
    strBtnStyle+="QRadioButton:hover{border-image:url("+h+");}";//按钮高亮时的图片
    strBtnStyle+="QRadioButton:pressed{border-image:url("+p+");}";//按钮按下时的图片
    strBtnStyle+="QRadioButton::indicator{width:0px;height:0px;}";//隐藏自带的圆圈

    pBtn->setStyleSheet(strBtnStyle);
}

bool SktSetStyle::SktLoadQssFile(const QString qssFile)
{
    QFile qss(qssFile);
    bool bRet=qss.open(QFile::ReadOnly);
    if(!bRet)
        return bRet;

    qApp->setStyleSheet(qss.readAll());
    qss.close();
    return true;
}

void SktSetStyle::SktSetWdtBack(QWidget *pWdt,const char *pstPath)
{
    pWdt->setAutoFillBackground(true);
    QPalette palette=pWdt->palette();
    palette.setBrush(pWdt->backgroundRole(),QBrush(QPixmap(pstPath).scaled(pWdt->size())));
    pWdt->setPalette(palette);
}
