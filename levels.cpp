#include "levels.h"
#include <string>
#include <fstream>
#include <QDebug>
#include <QFile>

Levels::Levels() {
    qDebug() << "pre file system";
    QFile file(":/Levels/levels.txt");
    QTextStream in(&file);

    while(!in.atEnd()) {
        qDebug() << "in";
        QString line = in.readLine();
        QStringList fields = line.split(" ");
        qDebug() << line;
        int size = fields[0].toInt();
        levels.push_back(Grid(size, fields[1]));
    }
}

Grid Levels::getLevel(int level) {
    if(levels.size() > level)
        return levels[level];
    else
        return Grid(10);
}
