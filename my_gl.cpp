#include<QDebug>
#include "my_gl.h"

#include "tile.h"
#include "grid.h"
#include "draw.h"
#include "mainwindow.h"
#include "levels.h"

MyGL::MyGL(QWidget *parent) : QOpenGLWidget(parent)
{
//    timerId = startTimer(30); // ~33 fps
}

MyGL::~MyGL() {
    killTimer(timerId);
}

void MyGL::initializeGL()
{
    glClearColor(0.15, 0.15, 0.15, 0.0);
}


int i = 0;
void MyGL::paintGL()
{
//    qDebug() << "Calling paintGL()";
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


//    Tile::setSideLength(0.25f);

//    Tile t;

//    t.draw(0.25f + ((float) i) / 4000, 0.25f + ((float) i) / 4000);
    Levels l;
    qDebug() << "Done with levels";
    Grid g = l.getLevel(0);
    g.draw();

    glFlush();
}

void MyGL::update() {
//    qDebug() << "Calling update()";
    paintGL();
    i = (i + 1) % 1000;
}

void MyGL::timerEvent(QTimerEvent *event)
{
    update();
}
