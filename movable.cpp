#include "movable.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QLabel>

Ui::MainWindow ui;

Movable::Movable() {}

Movable::Movable(float x, float y, QString filename, QLabel* label){
    QPixmap pixmapObject(filename);
    label->setPixmap(pixmapObject);// Sets image in the label
    label->setScaledContents(true); //Scales the image to the label size
    label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    this -> label = label;
    label->move(QPoint(x, y)); //Places the image in the desired location
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

void Movable::setLives(int lives, QLabel* label){
    displayLives = "Lives: ";
    displayLives += QString::number(lives);
    qDebug() << displayLives;
    label->setText(displayLives);
};

void Movable::hitbox(){

};
