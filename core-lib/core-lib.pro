# exlude gui module from qt as this is c++ library
QT -= gui
QT += sql

# name of lib exe: core-lib.dll
TARGET = core-lib

# template to tell qmake to create shared lib
TEMPLATE = lib

# used in *_global.h to export shared symbols
DEFINES += CORELIB_LIBRARY

# c++ version
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    album.cpp \
    albumdao.cpp \
    albummodel.cpp \
    dbmanager.cpp \
    gallery.cpp \
    picture.cpp \
    picturedao.cpp

# search path for includes
#INCLUDEPATH += Headers

HEADERS += \
    album.h \
    albumdao.h \
    albummodel.h \
    core-lib_global.h \
    dbmanager.h \
    gallery.h \
    picture.h \
    picturedao.h

# Default rules for deployment:
# install path of shared lib
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
