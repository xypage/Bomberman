#ifndef LEVELS_H
#define LEVELS_H

#include "grid.h"
#include <vector>

class Levels
{
    std::vector<Grid> levels;
public:
    Levels();
    Grid getLevel(int = 0);
};

#endif // LEVELS_H
