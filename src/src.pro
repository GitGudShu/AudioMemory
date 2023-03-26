TEMPLATE = app
TARGET = memoryaudio
INCLUDEPATH += .
LIBS += -ltag

QT = core gui widgets 
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

# Input
HEADERS += menu.h level.h

SOURCES += main.cpp menu.cpp level.cpp

RESOURCES += resources.qrc

