#include "draw.h"
#include <GL/gl.h>

//Draw::Draw(int _height, int _width): width(_width), height(_height) {}

float convert(int asInt, int size) {
    return (float) asInt / size;
}


//void Draw::line(const Vec& v1, const Vec& v2) {
//    glBegin(GL_LINES);
//        glColor3f(0.0f, 1.0f, 1.0f);
//        glVertex2f(convert(v1.x, Draw::width), convert(v1.y, Draw::height));
//        glVertex2f(convert(v2.x, Draw::width), convert(v2.y, Draw::height));
//     glEnd();
//}
