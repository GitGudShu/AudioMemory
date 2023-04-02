TEMPLATE = app
TARGET = memoryaudio
INCLUDEPATH += .
LIBS += -ltag

QT = core gui widgets 
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

# Input
HEADERS += menu.h gameboard.h score.h

SOURCES += main.cpp menu.cpp gameboard.cpp score.cpp

RESOURCES += resources.qrc

