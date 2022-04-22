#include "vec.h"

Vec::Vec(): x(0), y(0) {}
Vec::Vec(int _x, int _y): x(_x), y(_y) {}


Vec Vec::add(Vec& other) {
    return Vec(x + other.x, y + other.y);
}

Vec Vec::add(int x2, int y2) {
    return Vec(x + x2, y + y2);
}

