#-------------------------------------------------
#
# Project created by QtCreator 2018-06-19T14:50:21
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StaffHub
TEMPLATE = app

INCLUDEPATH += $$PWD/include
include(CentralInterface/CentralInterface.pri)

INCLUDEPATH += $$PWD/include
include(Database/Database.pri)

INCLUDEPATH += $$PWD/include
include(DynamicProgressBar/DynamicProgressBar.pri)

INCLUDEPATH += $$PWD/include
include(ColorProgressBar/ColorProgressBar.pri)

INCLUDEPATH += $$PWD/include
include(RoundProgressBar/RoundProgressBar.pri)

INCLUDEPATH += $$PWD/include
include(SlideNavigation/SlideNavigation.pri)

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    mainwidget.cpp \
    loginwidget.cpp \
    userinfo.cpp \
    CentralInterface/CentralInterface.cpp \
    LogicTier.cpp \
    Database/connectSQLite.cpp \
    Database/tableAdmin.cpp \
    Database/tableStaff.cpp \
    Database/viewBasic.cpp \
    CentralInterface/advancedFilter.cpp \
    Database/DBagent.cpp \
    CentralInterface/addColumn.cpp \
    Delegate/combodelegate.cpp \
    Delegate/datedelegate.cpp \
    Delegate/spindelegate.cpp \
    CentralInterface/dropColumn.cpp \
    DynamicProgressBar/circlewait.cpp \
    DynamicProgressBar/donutwait.cpp \
    DynamicProgressBar/linewait.cpp \
    DynamicProgressBar/piewait.cpp \
    DynamicProgressBar/taichiwait.cpp \
    DynamicProgressBar/zoomcirclewait.cpp \
    waitWidget.cpp \
    ColorProgressBar/colorprogressbar.cpp \
    RoundProgressBar/roundprogressbar.cpp \
    SlideNavigation/slidenavigation.cpp

HEADERS += \
    loginwidget.h \
    mainwidget.h \
    userInfo.h \
    CentralInterface/CentralInterface.h \
    LogicTier.h \
    Database/connectSQLite.h \
    Database/tableAdmin.h \
    Database/tableStaff.h \
    Database/viewBasic.h \
    CentralInterface/advancedFilter.h \
    Database/DBagent.h \
    CentralInterface/addColumn.h \
    Delegate/combodelegate.h \
    Delegate/datedelegate.h \
    Delegate/spindelegate.h \
    CentralInterface/dropColumn.h \
    DynamicProgressBar/circlewait.h \
    DynamicProgressBar/donutwait.h \
    DynamicProgressBar/linewait.h \
    DynamicProgressBar/piewait.h \
    DynamicProgressBar/taichiwait.h \
    DynamicProgressBar/zoomcirclewait.h \
    waitWidget.h \
    ColorProgressBar/colorprogressbar.h \
    RoundProgressBar/roundprogressbar.h \
    SlideNavigation/slidenavigation.h

FORMS += \
    loginwidget.ui \
    mainwidget.ui \
    CentralInterface/CentralInterface.ui \
    CentralInterface/advancedFilter.ui \
    CentralInterface/addColumn.ui \
    CentralInterface/dropColumn.ui \
    waitWidget.ui

DISTFILES +=

RESOURCES += \
    qss.qrc
