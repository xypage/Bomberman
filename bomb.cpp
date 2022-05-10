#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include "tile.h"
#include "bomb.h"
#include "grid.h"
#include <QGraphicsOpacityEffect>

Bomb::Bomb(){
    this -> strength = 0;
    posX = 0;
    posY = 0;
}

Bomb::Bomb(float posX, float posY, float imgX, float imgY, QString filename, QLabel* label){
    QPixmap pixmapObject(filename);
    label->setPixmap(pixmapObject);// Sets image in the label
    label->setScaledContents(true); //Scales the image to the label size
    label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    label->move(QPoint(imgX, imgY)); //Places the image in the desired location
    this -> label = label;
    this->posX = posX;
    this -> posY = posY;
};

void Bomb::setStrength(int strength){
    this -> strength += strength;
}

void Bomb::explode(){
    label->setAttribute(Qt::WA_TranslucentBackground);
    label->repaint();
}

void Bomb::remove(){

}

void Bomb::draw(float y, float x){

}


