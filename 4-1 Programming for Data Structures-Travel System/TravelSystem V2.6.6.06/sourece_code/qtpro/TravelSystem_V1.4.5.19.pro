#-------------------------------------------------
#
# Project created by QtCreator 2016-04-16T20:17:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newpic
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    input.cpp \
    Graph.cpp \
    simulation.cpp \
    firstinput.cpp \
    search.cpp

HEADERS  += mainwindow.h \
    input.h \
    Graph.h \
    struct&typ.h \
    newlabel.h \
    firstinput.h \
    search.h

FORMS    += \
    search.ui \
    firstinput.ui \
    input.ui \
    mainwindow.ui

DISTFILES +=

RESOURCES += \
    testinput.qrc
