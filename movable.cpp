#include "movable.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "levels.h"
#include <QKeyEvent>
#include <QDebug>
#include <QLabel>

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
};

float Movable::getX(){
    return label->x();
};

float Movable::getY(){
    return label->y();
};

void Movable::move(float x, float y){
    label->move(QPoint(label->x() + x, label->y() + y));
    tileX = (int) ((getX() + label->width() / 2.0f) * Levels::getWidth() / width);
    tileY = (int) ((getY() - 16 + label->height() / 2.0f) * Levels::getHeight() / (height - 16));
};

void Movable::setLives(int lives, QLabel* label){
    displayLives = "Lives: ";
    displayLives += QString::number(lives);
    qDebug() << displayLives;
    label->setText(displayLives);
    if(lives < 2){
//        move(100, 100);
    }
};

int Movable::getTileX(){
    return tileX;
}

int Movable::getTileY(){
    return tileY;
}
void Movable::hitbox(Movable enemy, QLabel* livesLabel){
    if(label->x() + label->width() >= enemy.label->x() && label->x() + label->width() <= enemy.label->x() + enemy.label->width()){
        if(label->y() - label->height() <= enemy.label->y() && label->y() - label->height() >= enemy.label->y() - enemy.label->height()){
            setLives(this->lives-1, livesLabel);
        }
    }
    else if(label->x() >= enemy.label->x() && label->x() <= enemy.label->x() + enemy.label->width()){
        if(label->y() <= enemy.label->y() && label->y() >= enemy.label->y() - enemy.label->height()){
           setLives(this->lives-1, livesLabel);
        }
    }
}
