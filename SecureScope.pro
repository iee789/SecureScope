QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    sktcmasys.cpp \
    sktmediaplayer.cpp \
    sktsetstyle.cpp \
    skttraymenu.cpp

HEADERS += \
    sktcmasys.h \
    sktmediaplayer.h \
    sktsetstyle.h \
    skttraymenu.h

FORMS += \
    sktcmasys.ui

INCLUDEPATH += $$PWD/sdk/include
LIBS += $$PWD/sdk/lib/libvlc.lib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    SktCmaSys.qrc

DISTFILES += \
    SktPicPath/1.ico \
    SktPicPath/1.png \
    SktPicPath/102.png \
    SktPicPath/103.png \
    SktPicPath/11-1_03.png \
    SktPicPath/2.ico \
    SktPicPath/2d11.png \
    SktPicPath/2d12.png \
    SktPicPath/3.ico \
    SktPicPath/3.png \
    SktPicPath/4.ico \
    SktPicPath/add.png \
    SktPicPath/add2.png \
    SktPicPath/bk.png \
    SktPicPath/button_bg.png \
    SktPicPath/cma_03-07-.png \
    SktPicPath/cma_03-07.png \
    SktPicPath/cma_03-09-.png \
    SktPicPath/cma_03-09.png \
    SktPicPath/cma_03-1-8.png \
    SktPicPath/cma_03-11-.png \
    SktPicPath/cma_03-11.png \
    SktPicPath/cma_03-16-.png \
    SktPicPath/cma_03-16.png \
    SktPicPath/cma_03-17-.png \
    SktPicPath/cma_03-17.png \
    SktPicPath/cma_03-18.png \
    SktPicPath/cma_03-22-.png \
    SktPicPath/cma_03-22.png \
    SktPicPath/cma_03-23-.png \
    SktPicPath/cma_03-23.png \
    SktPicPath/cma_03-24-.png \
    SktPicPath/cma_03-24.png \
    SktPicPath/down2.png \
    SktPicPath/icon_01.png \
    SktPicPath/icon_01h.png \
    SktPicPath/icon_02.png \
    SktPicPath/icon_02h.png \
    SktPicPath/icon_03.png \
    SktPicPath/icon_03h.png \
    SktPicPath/icon_04.png \
    SktPicPath/icon_04h.png \
    SktPicPath/icon_05.png \
    SktPicPath/icon_05h.png \
    SktPicPath/icon_Load .png \
    SktPicPath/icon_Load h.png \
    SktPicPath/icon_close.png \
    SktPicPath/icon_closeh.png \
    SktPicPath/icon_closez.png \
    SktPicPath/icon_down.png \
    SktPicPath/icon_downh.png \
    SktPicPath/icon_downz.png \
    SktPicPath/icon_home.png \
    SktPicPath/icon_homeh.png \
    SktPicPath/icon_jiankong .png \
    SktPicPath/icon_jiankong h.png \
    SktPicPath/icon_max.png \
    SktPicPath/icon_maxh.png \
    SktPicPath/icon_small.png \
    SktPicPath/icon_smallh.png \
    SktPicPath/icon_smallz.png \
    SktPicPath/icon_speaker.png \
    SktPicPath/logo.png \
    SktPicPath/pic_01.png \
    SktPicPath/pic_02h.png \
    SktPicPath/shezhi.png \
    SktPicPath/skt.ico \
    SktPicPath/top.png
