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
    bool breakable;
    TileColor tc;
    // since tiles will be squares on a grid, each will be the same size, so we can just
    // store their side length as a static member of the class
    float sideLength;
public:
    Tile();
    Tile(bool solid, bool breakable, float sideLength); // only meant to be used for tiles drawing it
    Tile(TileColor, bool solid, bool breakable, float sideLength);

    bool isSolid();
    bool isBreakable();

    virtual void draw(float y, float x);

    void setSideLength(float);
    float getSideLength();
    void Explode(float x, float y, int strength);
};

class Breakable: public Tile {
public:
    Breakable(float sideLength);

    virtual void draw(float y, float x);
};

class Invincible: public Tile {
public:
    Invincible(float sideLength);

    virtual void draw(float y, float x);
};

enum Junction { open, closed };
class Floor: public Tile {
    Junction left, right, up, down;
public:
    Floor(float sideLength, Junction, Junction, Junction, Junction);

    virtual void draw(float y, float x);
};

#endif // TILE_H
