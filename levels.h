#ifndef LEVELS_H
#define LEVELS_H

#include "grid.h"
#include <vector>

class Levels
{
    std::vector<Grid*> levels;
    static int width, height;
    static float sideLength;
public:
    Levels();
    ~Levels();
    Grid* getLevel(int = 0);

    static int getWidth();
    static int getHeight();
    static int setWidth();
    static int setHeight();
    static float getSideLength();
};

#endif // LEVELS_H
