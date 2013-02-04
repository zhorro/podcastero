#-------------------------------------------------
#
# Project created by QtCreator 2013-01-30T00:21:02
#
#-------------------------------------------------

QT       += network
QT       -= gui

TARGET = fileDownloader
TEMPLATE = lib

DEFINES += FILEDOWNLOADER_LIBRARY

SOURCES += \
    downloadfactory.cpp

HEADERS +=\
    downloadfactory.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
