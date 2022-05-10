#include "movable.h"
#include <queue>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "levels.h"
#include <QKeyEvent>
#include <QDebug>
#include <QLabel>
#include <QRandomGenerator>

Ui::MainWindow ui;

Movable::Movable() {}

Movable::Movable(float x, float y, QString filename, QLabel* label, float height, float width){
    QPixmap pixmapObject(filename);
    label->setPixmap(pixmapObject);// Sets image in the label
    label->setScaledContents(true); //Scales the image to the label size
    label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    label->move(QPoint(x, y)); //Places the image in the desired location
    this -> label = label;
    this -> height = height;
    this -> width = width;
    move(0,0);
    desire = dir::none;
};

Tile* checkTile(int y, int x) {
    return LevelsWrapper::l->getLevel()->tileAt(y, x);
}

float Movable::getX(){
    return label->x();
};

float Movable::getY(){
    return label->y();
};

void Movable::move(float x, float y){
    label->move(QPoint(label->x() + x, label->y() + y));

//    leftEdge = (int) (( 20 + getX()) * Levels::getWidth() / width);
//    rightEdge = (int) ((getX() + label->width()/2) * Levels::getWidth() / width);
//    bottomEdge = (int) ((getY()) * Levels::getHeight() / (height - 16));
//    topEdge = (int) ((getY() - label->height() + 20) * Levels::getHeight() / (height - 16));
    float centerX = getX() + (label->width() / 2.0f);
    float centerY = getY() + label->height() / 2.0f - 16;
    tileX = (int) (centerX * Levels::getWidth() / width);
    tileY = (int) (centerY * Levels::getHeight() / height);

    leftEdge = (int) ((centerX - 20) * Levels::getWidth() / width);
    rightEdge = (int) ((centerX + 20) * Levels::getWidth() / width);
    topEdge = (int) ((centerY - 25) * Levels::getHeight() / height);
    bottomEdge = (int) ((centerY + 25) * Levels::getHeight() / height);
};

void Movable::setLives(int lives, QLabel* livesLabel){
    this -> lives = lives; // Sets lives
    displayLives = "Lives: ";
    displayLives += QString::number(this -> lives); // Converts to string
    qDebug() << displayLives;
    livesLabel->setText(displayLives); // Updates lives counter
    if(this -> lives < 3){ // Respawn
        label->move(QPoint(100, 100));
    }
};

int Movable::getTileX(){
    return tileX;
}

int Movable::getTileY(){
    return tileY;
}

QLabel* Movable::getLabel() {
    return this->label;
}

void Movable::hitbox(Movable enemy, QLabel* livesLabel){
//    bool rightSideOverlap = rightEdge >= enemy.leftEdge && leftEdge <= enemy.leftEdge;
//    bool leftSideOverlap = leftEdge <= enemy.rightEdge && rightEdge >= enemy.rightEdge;
//    bool topOverlap = topEdge <= enemy.bottomEdge && bottomEdge >= enemy.bottomEdge;
//    bool bottomOverlap = bottomEdge >= enemy.topEdge && topEdge <= enemy.topEdge;
//    if((rightSideOverlap || leftSideOverlap) && (topOverlap || bottomOverlap)) {
//        setLives(this->lives-1, livesLabel);
//    }
//    if(label->x() + label->width() >= enemy.label->x() && label->x() + label->width() <= enemy.label->x() + enemy.label->width()){
//        if(label->y() - label->height() <= enemy.label->y() && label->y() - label->height() >= enemy.label->y() - enemy.label->height()){
//            setLives(this->lives-1, livesLabel);
//        }
//    }
//    else if(label->x() >= enemy.label->x() && label->x() <= enemy.label->x() + enemy.label->width()){
//        if(label->y() <= enemy.label->y() && label->y() >= enemy.label->y() - enemy.label->height()){
//           setLives(this->lives-1, livesLabel);
//        }
//    }
    // if(tileX == enemy.getTileX() && tileY == enemy.getTileX()) {
    //     setLives(this->lives - 1, livesLabel);
    // }
    if(label ->x() == 100 && label -> y() == 100){
        //This is a safe space / spawn location where lives can't be lost
    }
    else if(label->x() + label->width() >= enemy.label->x() && label->x() + label->width() <= enemy.label->x() + enemy.label->width()){
        if(label->y() - label->height() <= enemy.label->y() && label->y() - label->height() >= enemy.label->y() - enemy.label->height()){
            setLives(lives - 1, livesLabel);
        }
    }
    else if(label->x() >= enemy.label->x() && label->x() <= enemy.label->x() + enemy.label->width()){
        if(label->y() <= enemy.label->y() && label->y() >= enemy.label->y() - enemy.label->height()){
            setLives(lives - 1, livesLabel);
        }
    }
}

bool Movable::attemptMoveLeft() {
    Tile* tile = checkTile(tileY, leftEdge);
    if(tile != nullptr && !tile->isSolid()) {
        move(-5.0f, 0);
        return true;
    }
    return false;
}
bool Movable::attemptMoveRight() {
    Tile* tile = checkTile(tileY, rightEdge);
    if(tile != nullptr && !tile->isSolid()) {
        move(5.0f, 0);
        return true;
    }
    return false;
}
bool Movable::attemptMoveUp() {
    Tile* tile = checkTile(topEdge, tileX);
    if(tile != nullptr && !tile->isSolid()) {
        move(0, -5.0f);
        return true;
    }
    return false;
}
bool Movable::attemptMoveDown() {
    Tile* tile = checkTile(bottomEdge, tileX);
    if(tile != nullptr && !tile->isSolid()) {
        move(0, 5.0f);
        return true;
    }
    return false;
}
bool Movable::attemptMove(dir d) {
    if(d == left)
        return attemptMoveLeft();
    else if(d == right)
        return attemptMoveRight();
    else if(d == up)
        return attemptMoveUp();
    else if(d == down)
        return attemptMoveDown();
    else
        return false; // if direction == none
}

void Movable::hunt(Movable prey) {
//    qDebug() << "Hunting";
    if(prey.getTileY() == tileY) {
        if(prey.getTileX() < tileX) {
            if(!checkTile(tileY, tileX + 1)->isSolid()) {
                desire = right;
                attemptMoveRight();
                return;
            }
        } else {
            if(!checkTile(tileY, tileX - 1)->isSolid()) {
                desire = left;
                attemptMoveLeft();
                return;
            }
        }
    } else if(prey.getTileX() == tileX) {
        if(prey.getTileY() < tileY) {
            if(!checkTile(tileY - 1, tileX)->isSolid()) {
                desire = up;
                attemptMoveUp();
                return;
            }
        } else {
            if(!checkTile(tileY + 1, tileX)->isSolid()) {
                desire = down;
                attemptMoveDown();
                return;
            }
        }
    }

    bool moved = attemptMove(desire);

    if(moved)
        return;

    if(tileX > prey.getTileX()) {
        if(tileY < prey.getTileY()) {
            if(tileX - prey.getTileX() > prey.getTileY() - tileY) {
                moved = attemptMoveRight();
                desire = right;
            } else {
                moved = attemptMoveUp();
                desire = up;
            }
        } else {
            if(tileX - prey.getTileX() > tileY - prey.getTileY()) {
                moved = attemptMoveRight();
                desire = right;
            } else {
                moved = attemptMoveDown();
                desire = down;
            }
        }
    } else {
        if(tileY < prey.getTileY()) {
            if(prey.getTileX() - tileX > prey.getTileY() - tileY) {
                moved = attemptMoveLeft();
                desire = left;
            } else {
                moved = attemptMoveUp();
                desire = up;
            }
        } else {
            if(prey.getTileX() - tileX > tileY - prey.getTileY()) {
                moved = attemptMoveLeft();
                desire = left;
            } else {
                moved = attemptMoveDown();
                desire = down;
            }
        }
    }
//    qDebug() << moved << desire;
    while(!moved) {
        quint32 value = QRandomGenerator::global()->generate() % 4;
        moved = attemptMove(dir(value));
        desire = dir(value);
    }
}

void Movable::huntDirect(Movable prey) {

    Grid* g = LevelsWrapper::l->getLevel();
    int rows = g->getRows();
    int cols = g->getCols();

    int** weightedGrid = new int*[rows];
    for(int currentY = 0; currentY < rows; currentY++) {
        weightedGrid[currentY] = new int[cols];
        for(int currentX = 0; currentX < cols; currentX++) {
            if(g->tileAt(currentY, currentX)->isSolid()) {
                weightedGrid[currentY][currentX] = -1;
            } else {
                // just meant to be larger than any actual weight will be
                weightedGrid[currentY][currentX] = rows * cols * 2;
            }
        }
    }
    weightedGrid[prey.getTileY()][prey.getTileX()] = 0;
    std::queue<QPoint> q;
    q.push(QPoint(prey.getTileX(), prey.getTileY()));
    while(!q.empty()) {
        QPoint current = q.front();
        q.pop();

        int currentWeight = weightedGrid[current.y()][current.x()];
        if(current.y() < rows - 2 && weightedGrid[current.y() + 1][current.x()] > currentWeight + 1) {
            weightedGrid[current.y() + 1][current.x()] = currentWeight + 1;
            q.push(QPoint(current.x(), current.y() + 1));
        }
        if(current.y() > 1 && weightedGrid[current.y() - 1][current.x()] > currentWeight + 1) {
            weightedGrid[current.y() - 1][current.x()] = currentWeight + 1;
            q.push(QPoint(current.x(), current.y() - 1));
        }

        if(current.x() < cols - 2 && weightedGrid[current.y()][current.x() + 1] > currentWeight + 1) {
            weightedGrid[current.y()][current.x() + 1] = currentWeight + 1;
            q.push(QPoint(current.x() + 1, current.y()));
        }
        if(current.x() > 1 && weightedGrid[current.y()][current.x() - 1] > currentWeight + 1) {
            weightedGrid[current.y()][current.x() - 1] = currentWeight + 1;
            q.push(QPoint(current.x() - 1, current.y()));
        }
    }

    int min = rows * cols * 2;
    dir minDir = none;
    if(tileX > 1 && weightedGrid[tileY][tileX - 1] != -1 && weightedGrid[tileY][tileX - 1] < min) {
        min = weightedGrid[tileY][tileX - 1];
        minDir = left;
    }
    if(tileX < cols - 2 && weightedGrid[tileY][tileX + 1] != -1 && weightedGrid[tileY][tileX + 1] < min) {
        min = weightedGrid[tileY][tileX + 1];
        minDir = right;
    }
    if(tileY > 1 && weightedGrid[tileY - 1][tileX] != -1 && weightedGrid[tileY - 1][tileX] < min) {
        min = weightedGrid[tileY - 1][tileX];
        minDir = up;
    }
    if(tileY < rows - 2 && weightedGrid[tileY + 1][tileX] != -1 && weightedGrid[tileY + 1][tileX] < min) {
        min = weightedGrid[tileY + 1][tileX];
        minDir = down;
    }

    // when it's very close this method struggles
    attemptMove(minDir);


    for(int currentY = 0; currentY < rows; currentY++) {
        delete[] weightedGrid[currentY];
    }
    delete[] weightedGrid;
}
