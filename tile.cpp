#include "tile.h"
#include <GL/gl.h>
#include <QDebug>

float Tile::sideLength;

Tile::Tile():
    solid(false), destructible(false), tc(Red) {};
Tile::Tile(TileColor _tc, bool _solid, bool _destructible):
    solid(_solid), destructible(_destructible), tc(_tc) {}

bool Tile::isSolid() {
    return solid;
}
bool Tile::isDestructible() {
    return destructible;
}

// pass in top right corner
void Tile::draw(float y, float x) {
    qDebug() << y << " " << x << " " << sideLength;
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
    Tile::sideLength = _sideLength;
}
float Tile::getSideLength() {
    return Tile::sideLength;
}

