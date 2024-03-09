#ifndef SKTSETSTYLE_H
#define SKTSETSTYLE_H

#include <QPushButton>
#include <QString>
#include <QFile>
#include <QApplication>
#include <QRadioButton>

class SktSetStyle
{
public:
    SktSetStyle();

    void SktSetBtnStyle(QPushButton *pBtn,QString n,QString h,QString p);
    void SktRadioBtnStyle(QRadioButton *pBtn,QString n,QString h,QString p);

    bool SktLoadQssFile(const QString qssFile);
    void SktSetWdtBack(QWidget *pWdt,const char *pstPath);//设置背景图
};

#endif // SKTSETSTYLE_H
