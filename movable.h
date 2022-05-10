#ifndef MOVABLE_H
#define MOVABLE_H

#include <QtOpenGL>
#include <QString>
#include <QLabel>

enum dir {up, down, left, right, none};

class Movable{
private:
    // x and y position of the image
    int lives;
    float x, y, height, width;
    int tileX, tileY;
    QLabel* label;
    QString displayLives;
    dir desire;

public:
    int leftEdge, rightEdge, topEdge, bottomEdge;
    Movable();
    Movable(float x, float y, QString filename, QLabel* label, float height, float width);
    float getX(); // Returns x
    float getY(); // Returns y
    void move(float x, float y);
    void setLives(int lives, QLabel* label);
    void hitbox(Movable enemy, QLabel* livesLabel); //Combination ofo width + x, and y + height?
    int getTileX();
    int getTileY();
    QLabel* getLabel();
    bool attemptMoveLeft();
    bool attemptMoveRight();
    bool attemptMoveUp();
    bool attemptMoveDown();
    bool attemptMove(dir);
    void hunt(Movable prey);
    void huntDirect(Movable prey);
};

#endif // MOVABLE_H
