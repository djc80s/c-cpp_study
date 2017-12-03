TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += core
QT +=  xml

SOURCES += main.cpp \
    SDK/rectangle.cpp \
    SDK/customException.cpp \
    Job/measuredObj.cpp \
    Job/measuredObjList.cpp \
    Job/board.cpp \
    App/dataGenerator.cpp \
    Job/inspectionData.cpp \
    App/appSetting.cpp \
    App/captureSetting.cpp \
    App/mainWindow.cpp \
    DB/blob.cpp \
    DB/sqlitedb.cpp \
    DB/sqlitedbtest.cpp

SUBDIRS += \
    3DAOI_grace.pro

HEADERS += \
    SDK/rectangle.hpp \
    SDK/customException.hpp \
    Job/measuredObj.hpp \
    Job/measuredObjList.hpp \
    Job/board.hpp \
    App/dataGenerator.hpp \
    Job/inspectionData.hpp \
    App/appSetting.hpp \
    App/captureSetting.hpp \
    App/mainWindow.hpp \
    DB/blob.hpp \
    DB/sqlitedb.hpp \
    DB/sqlitedbtest.hpp

INCLUDEPATH += $$PWD/../include/sqlite
INCLUDEPATH += $$PWD/../include

unix:LIBS += -L$$PWD/../lib/ -lsqlite3

unix:LIBS +=  -L/usr/lib/x86_64-linux-gnu\
-ldl

DISTFILES +=
