#include<QDebug>
#include "my_gl.h"

#include "tile.h"
#include "grid.h"
#include "draw.h"
#include "mainwindow.h"
#include "levels.h"



Levels l;
int currentLevel;
Grid* g;
MyGL::MyGL(QWidget *parent) : QOpenGLWidget(parent)
{
    int goalFPS = 5; // low for now to avoid unnecessary work, will probably be higher later
    // fps = 1000ms / num
    // num = 1000ms / fps
    int timerDelay = 1000 / goalFPS;
    timerId = startTimer(timerDelay);

    currentLevel = 0;
    g = l.getLevel(currentLevel);
}

MyGL::~MyGL() {
    killTimer(timerId);
}


void MyGL::initializeGL()
{
    glClearColor(0.15, 0.15, 0.15, 0.0);
}


void MyGL::paintGL()
{
//    qDebug() << "Calling paintGL()";
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    g->draw();

    glFlush();
}

void MyGL::update() {
//    qDebug() << "Calling update()";

    // update game logic things, like player/enemy positions





    // call paint now that everything is in place and just needs to be drawn
    paintGL();
}

void MyGL::timerEvent(QTimerEvent *event)
{
    update();
}
