#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "draw.h"
#include "vec.h"

#include <QKeyEvent>
#include <QDebug>
#include "movable.h"
#include "bomb.h"
#include "levels.h"
#include "my_gl.h"

Movable character;
Movable enemyCharacter;
Bomb bomb;

void moveToStart() {
    Grid* g = MyGL::getLevelsWrapper()->l->getLevel();
    float startX = g->getSpawnCol() * 600.0f / g->getCols() + 10;
    float startY = g->getSpawnRow() * 600.0f / g->getRows() + 26; // + 16 for top padding and + 10 for extra room
    character.move(startX - character.getX(), startY - character.getY());
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(600, 616));
    Grid* g = MyGL::getLevelsWrapper()->l->getLevel();
    character = Movable(0, 0, ":/img/MainCharacter.png", ui->playerLabel, this->height(), this->width());
    moveToStart();
    character.setLives(3, ui->lives);
    enemyCharacter = Movable(515, 530, ":/img/Enemy.png", ui->enemyLabel, this->height(), this->width());
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isSolid(int y, int x) {
    Tile* t = MyGL::getLevelsWrapper()->l->getLevel()->tileAt(y, x);
    if(t == nullptr) {
        qDebug() << "NULL isSolid";
        return true;
    } else
        return t->isSolid();
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    float y_inc = 0.0, x_inc = 0.0;

    int x = character.getTileX();
    int y = character.getTileY();

    if (event->key() == Qt::Key_W) {
        if (!isSolid(character.topEdge, x))
            y_inc = -5.0f;
    }
    if (event->key() == Qt::Key_S) {
        if (!isSolid(character.bottomEdge, x))
            y_inc = 5.0f;
    }
    if (event->key() == Qt::Key_A) {
        if (!isSolid(y, character.leftEdge))
            x_inc = -5.0f;
                //setPos(x()-5,y());
    }
    if (event->key() == Qt::Key_D) {
        if (!isSolid(y, character.rightEdge))
             x_inc = 5.0f;
    }
    if (event->key() == Qt::Key_Space) {
        bomb = Bomb(0.5, 0.5, character.getX(), character.getY(), ":/img/Utility.png", ui->bombLabel);
        bomb.explode();
        qDebug() << '(' << character.getTileX() << ',' << character.getTileY() << ')';
        qDebug() << character.leftEdge << character.topEdge;
        qDebug() << character.rightEdge << character.bottomEdge << '\n';
        Tile* t = MyGL::getLevelsWrapper()->l->getLevel()->tileAt(character.getTileY(), character.getTileX());
        qDebug() << t->isSolid() << t->isBreakable();
    }
    if(event->key() == Qt::Key_R) {
        moveToStart();
    }
    character.move(x_inc, y_inc);
}
