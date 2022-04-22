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

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
};

#endif // MY_GL_H
