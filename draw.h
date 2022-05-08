#ifndef DRAW_H
#define DRAW_H

#include "vec.h"
#include <QtOpenGL>

class Draw
{
private:
    // height/width of the grid
    static int width, height;
public:
    Draw(int, int);
    static void line(const Vec&, const Vec&);
    static void rectangle();
    static void square();
    static void ellipse();
};

#endif // DRAW_H
