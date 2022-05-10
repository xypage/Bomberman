#ifndef GRID_H
#define GRID_H

#include "tile.h"

class Grid
{
protected:
    int rows, cols;
    Tile*** tiles;
    int spawnRow, spawnCol;
//    QVector3D backgroundColor;
public:
    Grid();
    Grid(int); // square
    Grid(int, int); // rectangle
    Grid(int, QList<QByteArray>);
    Grid(int, int, QByteArray);
    ~Grid();

    void draw();
    int getRows();
    int getCols();
    int getSpawnRow();
    int getSpawnCol();

    Tile* tileAt(int, int);
};

#endif // GRID_H
