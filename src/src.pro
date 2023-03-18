TEMPLATE = app
TARGET = memoryaudio
INCLUDEPATH += .

QT = core gui widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Input
HEADERS += menu.h

SOURCES += main.cpp menu.cpp

RESOURCES += resources.qrc

