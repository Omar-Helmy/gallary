QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# name of exe
TARGET = gallery-desktop

# type is desktop UI
TEMPLATE = app

CONFIG += c++14

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
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui


# Link the core-lib to this app: (win and Linux)
# libs are added to var: LIBS += -L<pathToLibrary> -l<libraryName>
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../core-lib/release/ -lcore-lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../core-lib/debug/ -lcore-lib
else:unix: LIBS += -L$$OUT_PWD/../core-lib/ -lcore-lib
# specify core-lib header files
# $$OUT_PWD The absolute path to the output directory
# $$PWD     The absolute path of the current .pro file
INCLUDEPATH += $$PWD/../core-lib
DEPENDPATH += $$PWD/../core-lib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
