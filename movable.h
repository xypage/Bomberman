#ifndef MOVABLE_H
#define MOVABLE_H

#include <QtOpenGL>
#include <QString>
#include <QLabel>

class Movable{
private:
    // x and y position of the image
    static int width, height;
    float x, y;
    QLabel* label;
public:
    Movable();
    Movable(float x, float y, QString filename, QLabel* label);
    float getX(); // Returns x
    float getY(); // Returns y
    void move(float x, float y);
    void hitbox(); //Combination ofo width + x, and y + height?

};

#endif // MOVABLE_H
