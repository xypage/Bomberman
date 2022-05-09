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
    main.cpp \
    mainwindow.cpp \
    movable.cpp \
    my_gl.cpp \
#    simpleshape.cpp \
    tile.cpp

HEADERS += \
    draw.h \
    mainwindow.h \
    movable.h \
    my_gl.h \
#    simpleshape.h \
    tile.h

FORMS += \
    mainwindow.ui

lopengl32 {
    LIBS += -lopengl32
} else {
    LIBS += -lGL
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
