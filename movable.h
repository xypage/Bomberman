#ifndef MOVABLE_H
#define MOVABLE_H

#include <QtOpenGL>
#include <QString>
#include <QLabel>

class Movable{
private:
    // x and y position of the image
    static int x, y, width, height;
public:
    Movable(int x, int y, QString filename, QLabel label);
    int getX(); // Returns x
    int getY(); // Returns y
    void setX(int x);
    void setY(int y);
    void hitbox(); //Combination ofo width + x, and y + height?
};

#endif // MOVABLE_H
