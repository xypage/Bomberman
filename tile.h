#ifndef TILE_H
#define TILE_H

#include "vec.h"

class Tile
{
protected:
    // Vector for position at which it resides
    Vec pos;
    // solid means you can't walk through it
    bool solid;
    // destructible means it can be blown up
    bool destructible;

public:
    Tile();
    Tile(int, int, bool, bool);

    int getX();
    int getY();
    Vec getPos();
    bool isSolid();
    bool isDestructible();

    virtual void draw();
};

#endif // TILE_H
