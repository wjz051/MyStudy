#-------------------------------------------------
#
# Project created by QtCreator 2016-12-09T08:43:21
#
#-------------------------------------------------

QT       += widgets

TARGET = TreeTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    settings.cpp \
    treemodel.cpp \
    tablemodel.cpp \
    treedelegate.cpp \
    patheditor.cpp \
    tabledelegate.cpp

HEADERS  += mainwidget.h \
    settings.h \
    treemodel.h \
    tablemodel.h \
    treedelegate.h \
    patheditor.h \
    tabledelegate.h

TRANSLATIONS += zh_CN.ts

RC_ICONS = tree.ico

RESOURCES += \
    resources.qrc
