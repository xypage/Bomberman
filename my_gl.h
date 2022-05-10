#ifndef MY_GL_H
#define MY_GL_H

#include <QtWidgets>
#include <QtOpenGL>
#include <QtOpenGLWidgets>
#include <GL/glu.h>

class MyGL: public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit MyGL(QWidget *parent = 0);
    ~MyGL();
    void update();

protected:
    void initializeGL();
    void paintGL();
    void timerEvent(QTimerEvent *event);

private:
    int timerId;
};

#endif // MY_GL_H
