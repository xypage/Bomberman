#include "movable.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

Ui::MainWindow ui;

Movable::Movable() {}

Movable::Movable(float x, float y, QString filename, QLabel* label){
    QPixmap pixmapObject(filename);
    label->setPixmap(pixmapObject);
    this -> label = label;
};

float Movable::getX(){
    return label->x();
};

float Movable::getY(){
    return label->x();
};

void Movable::move(float x, float y){
    label->move(QPoint(label->x() + x, label->y() + y));
};

void Movable::setBreak(bool breakability){
    this -> breakablity = breakability;
};

bool Movable::breakable(){
    return breakablity;
};

void Movable::hitbox(){

};
