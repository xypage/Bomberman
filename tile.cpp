#include "tile.h"
#include <GL/gl.h>

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

void Tile::draw(float x, float y) {
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
            glVertex2f(x, y); // top left
            glVertex2f(x, y - sideLength); // bottom left
            glVertex2f(x - sideLength, y - sideLength); // bottom right
            glVertex2f(x - sideLength, y); // top right
         glEnd();
}

void Tile::setSideLength(float _sideLength) {
    Tile::sideLength = _sideLength;
}
