#-------------------------------------------------
#
# Project created by QtCreator 2012-10-01T12:02:49
#
#-------------------------------------------------

QT       += core webkit

TARGET = WebPageTraverser
CONFIG   += console
CONFIG   -= app_bundle

LIBS += "-lqjson"

TEMPLATE = app

SOURCES += src/main.cpp \
    src/webelement.cpp \
    src/pagetraverser.cpp

HEADERS += \
    src/webelement.h \
    src/pagetraverser.h

