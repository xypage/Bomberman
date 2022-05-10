#ifndef BOMB_H
#define BOMB_H

#include <QtOpenGL>
#include <QString>
#include <QLabel>
#include "tile.h"
#include "movable.h"

class Bomb : public Tile{
static int count;
int strength;
float posX, posY;
QLabel* label;
bool wasDropped;

public:
    Bomb();
    Bomb(float posx, float posy, float imgX, float imgy, QString filename, QLabel* label);
    void explode();
    void draw(float y, float x);
    void setStrength(int strength);
    void remove();
    void check(Movable enemy);
    bool dropped();
};

#endif // BOMB_H
