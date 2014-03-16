TEMPLATE = app

TARGET = harbour-prayer

QT += qml quick
CONFIG += link_pkgconfig
PKGCONFIG += qdeclarative5-boostable

VPATH += ../prayertimes/
INCLUDEPATH += ../prayertimes/
DEPENDPATH += ../prayertimes/

SOURCES += main.cpp \
           settings.cpp

HEADERS += prayertimes.hpp \
           settings.h

RESOURCES += ../qml/qml.qrc

QMAKE_CXXFLAGS += -std=c++0x #-Wall -W -Werror
