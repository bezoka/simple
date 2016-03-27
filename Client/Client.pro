TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    window.cpp \
    client.cpp \
    network.cpp

HEADERS += \
    window.h \
    client.h \
    network.h
