#-------------------------------------------------
#
# Project created by QtCreator 2016-08-23T12:59:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testHeadView
TEMPLATE = app
DESTDIR = $$PWD/bin

SOURCES += main.cpp\
        TcTableWidget.cpp \
    HHeaderItemDelegate.cpp \
    HHeaderModel.cpp \
    HHeaderView.cpp \
    VHeaderModel.cpp \
    VHeaderView.cpp \
    TcTableView.cpp \
    TcTabelModel.cpp

HEADERS  += TcTableWidget.h \
    HHeaderItemDelegate.h \
    HHeaderModel.h \
    HHeaderView.h \
    VHeaderModel.h \
    VHeaderView.h \
    TcTableView.h \
    TcTabelModel.h

FORMS    += TcTableWidget.ui

DISTFILES += \
    Readme.txt
