TEMPLATE = app
TARGET = AudioMemory
INCLUDEPATH += .

QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Input
HEADERS += window.h
SOURCES += main.cpp window.cpp
