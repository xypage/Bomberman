#ifndef TILE_H
#define TILE_H

#include "qvectornd.h"
#include "vec.h"

enum TileColor{ Red, Blue, Green, Purple };

class Tile
{
protected:
    // solid means you can't walk through it
    bool solid;
    // destructible means it can be blown up
    bool destructible;
    TileColor tc;
public:
    // since tiles will be squares on a grid, each will be the same size, so we can just
    // store their side length as a static member of the class
    float sideLength;
    Tile();
    Tile(TileColor, bool, bool);

    bool isSolid();
    bool isDestructible();

    virtual void draw(float x, float y);
    void setSideLength(float);
};

//float Tile::sideLength = 0.25f;

#endif // TILE_H
