#include "grid.h"
#include <QDebug>

Tile* temporaryTileConstructor(float sideLength) {
    static int colorCounter = 0;
    return new Tile(TileColor((colorCounter++)%4), false, false, sideLength);
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
    spawnRow = 1;
    spawnCol = 1;
    enemySpawnRow = 1;
    enemySpawnCol = 1;
    rows = size;
    cols = size;
    float sideLength = (2.0f / size);
    tiles = new Tile**[size];
    for(int y = 0; y < size; y++) {
        tiles[y] = new Tile*[size];
        for(int x = 0; x < size; x++) {
            tiles[y][x] = temporaryTileConstructor(sideLength);
        }
    }

    tiles[size/2][size/2] = new Breakable(sideLength);
    tiles[size/2 + 1][size/2] = new Invincible(sideLength);
    tiles[size/2 + 2][size/2] = new Invincible(sideLength);
    tiles[size/2 + 3][size/2] = new Invincible(sideLength);
    tiles[size/2 + 3][size/2 - 1] = new Invincible(sideLength);
    tiles[size/2 + 3][size/2 - 2] = new Invincible(sideLength);
    tiles[size/2 + 2][size/2 - 2] = new Invincible(sideLength);
}
Grid::Grid(int size, QList<QByteArray> level)
{
    spawnRow = 1;
    spawnCol = 1;
    enemySpawnRow = 1;
    enemySpawnCol = 1;
    rows = size;
    cols = size;
    float sideLength = (2.0f / size);
//    qDebug() << "Creating from string";
    tiles = new Tile**[size];
    for(int y = 0; y < size; y++) {
        tiles[y] = new Tile*[size];
        QByteArray row = level[y];
        for(int x = 0; x < size; x++) {
            QChar current = row[x];
//            qDebug() << y << x << current;
            if(current == 'b' || current == 'B') {
//                qDebug() << "in B";
                tiles[y][x] = new Breakable(sideLength);
            } else if(current == 'i' || current == 'I') {
//                qDebug() << "in I";
                tiles[y][x] = new Invincible(sideLength);
            } else if(current == 'e' || current == 'E') {
//                qDebug() << "in E";
                tiles[y][x] = temporaryTileConstructor(sideLength);
            } else if(current == 's' || current == 'S'){
//                qDebug() << "in spawn";
                spawnRow = y;
                spawnCol = x;
                tiles[y][x] = temporaryTileConstructor(sideLength);
            } else if(current == 'x' || current == 'X') {
//                qDebug() << "in enemy spawn";
                enemySpawnRow = y;
                enemySpawnCol = x;
                tiles[y][x] = temporaryTileConstructor(sideLength);
            }
        }
    }
//    qDebug() << "Done creating new grid";
}


void Grid::draw() {
    float sideLength = tiles[0][0]->getSideLength();
    for(int y = 0; y < rows; y++) {
        for(int x = 0; x < cols; x++) {
            float vert = 2.0f * y / rows - 1 + sideLength;
            float hor = 2.0f * x / cols - 1 + sideLength;
//            qDebug() << vert << " " << hor;
            tiles[rows - 1 - y][x]->draw(vert, hor);

        }
    }
}

void Grid::remove(int x, int y){
    float sideLength = tiles[0][0]->getSideLength();
    if(tiles[y][x]->isSolid() && tiles[y][x]->isBreakable()){
            delete (tiles[y][x]);
            tiles[y][x] = temporaryTileConstructor(sideLength);
//            tiles[y][x] ->isSolid() = false;
    }
}

int Grid::getCols() {
    return cols;
}
int Grid::getRows() {
    return rows;
}

int Grid::getSpawnCol() {
    return spawnCol;
}
int Grid::getSpawnRow() {
    return spawnRow;
}
int Grid::getEnemySpawnCol() {
    return enemySpawnCol;
}
int Grid::getEnemySpawnRow() {
    return enemySpawnRow;
}


Tile* Grid::tileAt(int y, int x) {
    if(y >= 0 && y < rows && x >= 0 && x < cols)
        return tiles[y][x];
    else
        return nullptr;
}

void Grid::change(int y, int x) {
    tiles[y][x] = temporaryTileConstructor(2.0f / rows);
//    qDebug() << "Changed";
}
