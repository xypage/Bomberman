#ifndef SIMPLESHAPE_H
#define SIMPLESHAPE_H

#include <vector>
#include "tile.h"

class SimpleShape : public Tile
{
protected:
    std::vector<float> color;
public:
    SimpleShape();
};

#endif // SIMPLESHAPE_H
