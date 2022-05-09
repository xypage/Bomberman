#ifndef GRID_H
#define GRID_H

#include "tile.h"

class Grid
{
protected:
    int rows, cols;
    Tile** tiles;
//    QVector3D backgroundColor;
public:
    Grid();
    Grid(int); // square
    Grid(int, int); // rectangle

    void draw();
};

#endif // GRID_H
