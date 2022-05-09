#include "grid.h"
#include <QDebug>

int Grid::rows, Grid::cols;

Tile* temporaryTileConstructor() {
    static int colorCounter = 0;
    return new Tile(TileColor((colorCounter++)%4), false, false);
}


Grid::Grid()
{}

Grid::~Grid() {
    for(int y = 0; y < rows; y++) {
        delete[] tiles[y];
    }
    delete[] tiles;
}


Grid::Grid(int size)
{
    rows = size;
    cols = size;
    tiles = new Tile**[size];
    for(int y = 0; y < size; y++) {
        tiles[y] = new Tile*[size];
        for(int x = 0; x < size; x++) {
            tiles[y][x] = temporaryTileConstructor();
        }
    }
    tiles[size/2][size/2] = new Breakable();
    tiles[size/2 + 1][size/2] = new Invincible();
    tiles[size/2 + 2][size/2] = new Invincible();
    tiles[size/2 + 3][size/2] = new Invincible();
    tiles[size/2 + 3][size/2 - 1] = new Invincible();
    tiles[size/2 + 3][size/2 - 2] = new Invincible();
    tiles[size/2 + 2][size/2 - 2] = new Invincible();
    Tile::setSideLength(2.0f / size);
}

Grid::Grid(int height, int width)
{
    rows = height;
    cols = height;
    tiles = new Tile**[height];
    for(int y = 0; y < height; y++) {
        tiles[y] = new Tile*[width];
        for(int x = 0; x < width; x++) {
            tiles[y][x] = temporaryTileConstructor();
        }
    }
    Tile::setSideLength(2.0f / height);
}
Grid::Grid(int size, QString level)
{
    rows = size;
    cols = size;
    qDebug() << "Creating from string";
    tiles = new Tile**[size];
    for(int y = 0; y < size; y++) {
        tiles[y] = new Tile*[size];
        for(int x = 0; x < size; x++) {
            QChar current = level[y * size + x];
            if(current == 'b' || current == 'B') {
                tiles[y][x] = new Breakable();
            } else if(current == 'i' || current == 'I') {
                tiles[y][x] = new Invincible();
            } else if(current == 'e' || current == 'E') {
                tiles[y][x] = temporaryTileConstructor();
            } else {
                tiles[y][x] = temporaryTileConstructor();
            }
        }
    }

}


void Grid::draw() {
    for(int y = 0; y < rows; y++) {
        for(int x = 0; x < cols; x++) {
            float vert = 2.0f * y / rows - 1 + Tile::getSideLength();
            float hor = 2.0f * x / cols - 1 + Tile::getSideLength();
//            qDebug() << vert << " " << hor;
            tiles[y][x]->draw(vert, hor);
        }
    }
}

int Grid::getWidth() {
    return cols;
}
int Grid::getHeight() {
    return rows;
}
