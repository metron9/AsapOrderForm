#-------------------------------------------------
#
# Project created by QtCreator 2015-08-03T21:44:16
#
#-------------------------------------------------

QT       += core gui
qtHaveModule(printsupport): QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testprint
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
