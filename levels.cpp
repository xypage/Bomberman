#include "levels.h"
#include <string>
#include <fstream>
#include <QDebug>
#include <QResource>
#include <QByteArray>

int Levels::width, Levels::height;
float Levels::sideLength;

Levels* LevelsWrapper::l = new Levels;

Levels::Levels() {
    QResource in(":/Levels/levels.txt");
    QList<QByteArray> levelStrings = in.uncompressedData().trimmed().split('\n');
    int pos = 0;
    QList<QByteArray> level;
    while(pos < levelStrings.length()) {
        if(levelStrings[pos].trimmed().isEmpty()) {
            pos++;
            continue;
        }
        int size = levelStrings[pos].toInt();
        for(int i = 1; i <= size; i++) {
            level.append(levelStrings[i + pos]);
        }
        levels.push_back(new Grid(size, level));
        level.clear();
        pos += size + 1;
    }
}

Levels::~Levels() {
    for(Grid* level : levels) {
        delete level;
    }
}

Grid* Levels::getLevel(int level) {
    qDebug() << levels.size() << level;
    if(levels.size() > level) {
        height = levels[level]->getRows();
        width = levels[level]->getCols();
        sideLength = levels[level]->tileAt(0,0)->getSideLength();
        return levels[level];
    }
    else {
        height = 10;
        width = 10;
        return new Grid(10);
    }
}

int Levels::getHeight() {
    return height;
}

int Levels::getWidth() {
    return width;
}

float Levels::getSideLength() {
    return sideLength;
}

int Levels::getLevelCount() {
    return levels.size();
}
