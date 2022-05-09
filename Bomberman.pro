QT       += \
    core gui \
    opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    draw.cpp \
    grid.cpp \
    levels.cpp \
    main.cpp \
    mainwindow.cpp \
    movable.cpp \
    my_gl.cpp \
    tile.cpp

HEADERS += \
    draw.h \
    grid.h \
    levels.h \
    mainwindow.h \
    movable.h \
    my_gl.h \
    tile.h

FORMS += \
    mainwindow.ui

win32: LIBS += -lopengl32
qnx: -lGL

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else:  unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Levels.qrc \
    images.qrc

DISTFILES += \
    levels.txt
