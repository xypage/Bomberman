#include<QDebug>
#include "my_gl.h"
#include "tile.h"
#include "grid.h"
#include "draw.h"
#include "mainwindow.h"
#include "levels.h"


LevelsWrapper* MyGL::getLevelsWrapper() {
    static LevelsWrapper* l = new LevelsWrapper();

    return l;
}

int currentLevel;
Grid* g;
MyGL::MyGL(QWidget *parent) : QOpenGLWidget(parent)
{
    float goalFPS = 10; // low for now to avoid unnecessary work, will probably be higher later
    // fps = 1000ms / num
    // num = 1000ms / fps
    int timerDelay = (int) (1000 / goalFPS);
    timerId = startTimer(timerDelay);

    currentLevel = 0;
    g = getLevelsWrapper()->l->getLevel(currentLevel);
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

    glClearColor(0.15, 0.15, 0.15, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glFlush();

    LevelsWrapper::l->getLevel()->draw();


//    glFlush();
}

void MyGL::update() {

}

void MyGL::timerEvent(QTimerEvent *event)
{
    MainWindow::update();
    paintGL();
    update();
    QWidget::update();

}
