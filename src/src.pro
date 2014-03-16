TEMPLATE = app

TARGET = harbour-prayer

QT += qml quick
CONFIG += link_pkgconfig
PKGCONFIG += qdeclarative5-boostable

SOURCES += main.cpp

RESOURCES += ../qml/qml.qrc
