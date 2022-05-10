#ifndef BOMB_H
#define BOMB_H

#include <QtOpenGL>
#include <QString>
#include <QLabel>
#include "tile.h"

class Bomb : public Tile{
static int count;
int strength;
float posX, posY;
QLabel* label;

public:
    Bomb();
    Bomb(float posx, float posy, float imgX, float imgy, QString filename, QLabel* label);
    void explode();
    void draw(float y, float x);
    void setStrength(int strength);
    void remove();
};

#endif // BOMB_H
