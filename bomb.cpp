#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include "tile.h"
#include "bomb.h"
#include "grid.h"
#include "movable.h"

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
//    if(!(tileX == LevelsWrapper::l->getLevel()->getSpawnCol() && tileY == LevelsWrapper::l->getLevel()->getSpawnRow()) &&
//            tileX == enemy.getTileX() && tileY == enemy.getTileY()) {
//        setLives(lives - 1, livesLabel);
//    }
}

bool Bomb::dropped(){
   return wasDropped;
}


void Bomb::check(Movable enemy){
   QLabel* enemylabel = enemy.getLabel();
   if(enemy.getX() >= label->x() && enemy.getX() <= label ->x() + label->width()) {
       if(enemy.getY() >= label->y() - label->height() && enemy.getY() <= label->y() ||
               enemy.getY() - enemylabel->height() < label->y() && enemy.getY() - enemylabel->height() >= label->y() - label->height()) {
           enemylabel->move(QPoint(500, 500));
       }
   }
   if(enemy.getX() + enemylabel->width() >= label->x() && enemy.getX() + enemylabel->width() <= label -> x() + label->width()){
       if(enemy.getY() >= label->y() - label->height() && enemy.getY() <= label->y() ||
               enemy.getY() - enemylabel->height() < label->y() && enemy.getY() - enemylabel->height() >= label->y() - label->height()) {
           enemylabel->move(QPoint(500, 500));
       }
   }
}


void Bomb::remove(){
        for(int i = 0; i < strength; i++){
//        name.remove(posX + i, posY);
//        name.remove(posX, posY + i);
//        name.remove(posX - i, posY);
//        name.remove(posX, posY - i);
    }
}

void Bomb::draw(float y, float x){

}


