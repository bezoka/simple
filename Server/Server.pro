TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS = -std=c++11
LIBS += -pthread

SOURCES += main.cpp \
    World/world.cpp \
    World/Item/bow.cpp \
    World/Item/crossbow.cpp \
    World/Item/sword.cpp \
    World/Creature/human.cpp \
    server.cpp \
    World/Item/item.cpp \
    World/Ground/ground.cpp \
    network.cpp \
    Network/client.cpp \
    window.cpp \
    game.cpp

HEADERS += \
    World/world.h \
    World/Item/bow.h \
    World/Item/crossbow.h \
    World/Item/sword.h \
    World/Creature/human.h \
    server.h \
    World/Item/item.h \
    World/Ground/ground.h \
    network.h \
    Network/client.h \
    window.h \
    game.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/release/ -lBox2D
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/debug/ -lBox2D
else:unix: LIBS += -L$$PWD/../../../../../../../usr/lib/ -lBox2D

INCLUDEPATH += $$PWD/../../../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../../../usr/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../lib/release/ -lsfml-graphics
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../lib/debug/ -lsfml-graphics
else:unix: LIBS += -L$$PWD/../../../../../../../lib/ -lsfml-graphics

INCLUDEPATH += $$PWD/../../../../../../../
DEPENDPATH += $$PWD/../../../../../../../


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/release/ -lsfml-window
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/debug/ -lsfml-window
else:unix: LIBS += -L$$PWD/../../../../../../../usr/lib/ -lsfml-window

INCLUDEPATH += $$PWD/../../../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../../../usr/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/release/ -lsfml-system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/debug/ -lsfml-system
else:unix: LIBS += -L$$PWD/../../../../../../../usr/lib/ -lsfml-system

INCLUDEPATH += $$PWD/../../../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../../../usr/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/release/ -lsfml-network
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/debug/ -lsfml-network
else:unix: LIBS += -L$$PWD/../../../../../../../usr/lib/ -lsfml-network

INCLUDEPATH += $$PWD/../../../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../../../usr/include
