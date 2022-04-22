#include "tile.h"

Tile::Tile():
    pos(Vec()), solid(false), destructible(false) {};

Tile::Tile(int x, int y, bool _solid = true, bool _destructible = false):
    pos(Vec(x, y)), solid(_solid), destructible(_destructible) {}

int Tile::getX() {
    return pos.x;
}
int Tile::getY() {
    return pos.y;
}
Vec Tile::getPos() {
    return Vec(pos);
}
bool Tile::isSolid() {
    return solid;
}
bool Tile::isDestructible() {
    return destructible;
}

void Tile::draw(){}
