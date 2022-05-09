#include "grid.h"
#include <QDebug>

Tile temporaryTileConstructor() {
    static int colorCounter = 0;
    return Tile(TileColor((colorCounter++)%4), false, false);
}


Grid::Grid()
{}

Grid::Grid(int size): rows(size), cols(size)
{
    tiles = new Tile*[size];
    for(int y= 0; y < size; y++) {
        tiles[y] = new Tile[size];
        for(int x = 0; x < size; x++) {
            tiles[y][x] = temporaryTileConstructor();
        }
    }
    Tile::setSideLength(2.0f / size);
}

Grid::Grid(int height, int width): rows(height), cols(width)
{
    tiles = new Tile*[height];
    for(int y= 0; y < height; y++) {
        tiles[y] = new Tile[width];
        for(int x = 0; x < width; x++) {
            tiles[y][x] = temporaryTileConstructor();
        }
    }
    Tile::setSideLength(2.0f / height);
}

void Grid::draw() {
    for(int y = 0; y < rows; y++) {
        for(int x = 0; x < cols; x++) {
            float vert = 2.0f * y / rows - 1 + Tile::getSideLength();
            float hor = 2.0f * x / cols - 1 + Tile::getSideLength();
            qDebug() << vert << " " << hor;
            tiles[y][x].draw(vert, hor);
        }
    }
}
