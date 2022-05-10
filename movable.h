#ifndef MOVABLE_H
#define MOVABLE_H

#include <QtOpenGL>
#include <QString>
#include <QLabel>

class Movable{
private:
    // x and y position of the image
    static int  lives;
    float x, y, tileX, tileY, height, width;
    QLabel* label;
    QString displayLives;

public:
    Movable();
    Movable(float x, float y, QString filename, QLabel* label, float height, float width);
    float getX(); // Returns x
    float getY(); // Returns y
    void move(float x, float y);
    void setLives(int lives, QLabel* label);
    void hitbox(); //Combination ofo width + x, and y + height?
    float getTileX();
    float getTileY();
};

#endif // MOVABLE_H
