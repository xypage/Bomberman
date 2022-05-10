#ifndef LEVELS_H
#define LEVELS_H

#include "grid.h"
#include <vector>

class Levels
{
    std::vector<Grid*> levels;
    static int width, height;
public:
    Levels();
    ~Levels();
    Grid* getLevel(int = 0);

    static int getWidth();
    static int getHeight();
    static int setWidth();
    static int setHeight();
};

#endif // LEVELS_H
