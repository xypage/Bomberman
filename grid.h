#ifndef GRID_H
#define GRID_H

#include "tile.h"

class Grid
{
protected:
    static int rows, cols;
    Tile*** tiles;
//    QVector3D backgroundColor;
public:
    Grid();
    Grid(int); // square
    Grid(int, int); // rectangle
    Grid(int, QString);
    Grid(int, int, QString);
    ~Grid();


    void draw();
    static int getWidth();
    static int getHeight();
};

#endif // GRID_H
