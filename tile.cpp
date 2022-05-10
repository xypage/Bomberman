#include "tile.h"
#include <GL/gl.h>
#include <QDebug>

Tile::Tile():
    solid(false), breakable(false), tc(Red) {};
Tile::Tile(TileColor _tc, bool _solid, bool _breakable, float _sideLength):
    solid(_solid), breakable(_breakable), tc(_tc), sideLength(_sideLength) {}
Tile::Tile(bool _solid, bool _breakable, float _sideLength):
    solid(_solid), breakable(_breakable), sideLength(_sideLength) {}

bool Tile::isSolid() {
    return solid;
}
bool Tile::isBreakable() {
    return breakable;
}

// pass in top right corner
void Tile::draw(float y, float x) {
//    qDebug() << y << " " << x << " " << sideLength;
        glBegin(GL_LINE_LOOP);
            if(this->tc == Red) {
                glColor3f(1.0f, 0.0f, 0.0f);
            } else if(this->tc == Blue) {
                glColor3f(0.0f, 0.0f, 1.0f);
            } else if(this->tc == Green) {
                glColor3f(0.0f, 1.0f, 0.0f);
            } else if(this->tc == Purple) {
                glColor3f(0.8f, 0.0f, 0.8f);
            }
            glVertex2f(x             , y             ); // top right
            glVertex2f(x - sideLength, y             ); // top left
            glVertex2f(x - sideLength, y - sideLength); // bottom left
            glVertex2f(x             , y - sideLength); // bottom right
         glEnd();
}

void Tile::setSideLength(float _sideLength) {
    sideLength = _sideLength;
}
float Tile::getSideLength() {
    return sideLength;
}

void drawBrick(float x, float y, float sideLength, float r1, float g1, float b1, float r2, float g2, float b2) {
    float full = sideLength;
    glBegin(GL_POLYGON);
    glColor3f(r1, g1, b1);
        glVertex2f(x             , y             ); // top right
        glVertex2f(x - full, y             ); // top left
        glVertex2f(x - full, y - full); // bottom left
        glVertex2f(x             , y - full); // bottom right
     glEnd();

    float half = full / 2;
    float quarter = full / 4;

    // top right brick
    glColor3f(r2, g2, b2);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x - half, y);
        glVertex2f(x - half, y - quarter);
        glVertex2f(x, y - quarter);
    glEnd();

    // top left
    glBegin(GL_LINE_LOOP);
        glVertex2f(x - half, y);
        glVertex2f(x - full, y);
        glVertex2f(x - full, y - quarter);
        glVertex2f(x - half, y - quarter);
    glEnd();

    // second row brick
    glBegin(GL_LINE_LOOP);
        glVertex2f(x - quarter, y - quarter);
        glVertex2f(x - half - quarter, y - quarter);
        glVertex2f(x - half - quarter, y - half);
        glVertex2f(x - quarter, y - half);
    glEnd();

    // middle right brick
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y - half);
        glVertex2f(x - half, y - half);
        glVertex2f(x - half, y - half - quarter);
        glVertex2f(x, y - half - quarter);
    glEnd();

    // middle left brick
    glBegin(GL_LINE_LOOP);
        glVertex2f(x - half, y - half);
        glVertex2f(x - full, y - half);
        glVertex2f(x - full, y - half - quarter);
        glVertex2f(x - half, y - half - quarter);
    glEnd();

    // bottom brick
    glBegin(GL_LINE_LOOP);
        glVertex2f(x - quarter, y - half - quarter);
        glVertex2f(x - half - quarter, y - half - quarter);
        glVertex2f(x - half - quarter, y - full);
        glVertex2f(x - quarter, y - full);
    glEnd();
}

void Tile::Explode(float x, float y, int strength){
    int r, g, b;
    if (strength >= 3){
        r = 255;
        g = 0;
        b = 0;
    }
    else if(strength == 2){
        r = 245;
        g = 60;
        b = 0;
    }
    else{
        r = 245;
        g = 165;
        b = 30;
    }
    float full = sideLength;
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
        glVertex2f(x             , y             ); // top right
        glVertex2f(x - full, y             ); // top left
        glVertex2f(x - full, y - full); // bottom left
        glVertex2f(x             , y - full); // bottom right
     glEnd();
}

void Tile::Remove(float x, float y){
    float full = sideLength;
    glBegin(GL_POLYGON);
    glColor3f(255, 255, 255);
        glVertex2f(x             , y             ); // top right
        glVertex2f(x - full, y             ); // top left
        glVertex2f(x - full, y - full); // bottom left
        glVertex2f(x             , y - full); // bottom right
     glEnd();
}

Breakable::Breakable(float _sideLength): Tile(true, true, _sideLength) {};

void Breakable::draw(float y, float x) {
 drawBrick(x, y, sideLength, 0.6784313725, 0.1764705882, 0.0392156863, 0.7686274510, 0.7843137255, 0.8078431373);
}

Invincible::Invincible(float _sideLength): Tile(true, false, _sideLength) {};

void Invincible::draw(float y, float x) {
    drawBrick(x, y, sideLength, 0.3137254902, 0.3137254902, 0.3137254902, 0.7686274510, 0.7843137255, 0.8078431373);
}

