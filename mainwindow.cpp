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
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(600, 616));
    Grid* g = MyGL::getLevelsWrapper()->l->getLevel();
    float startX = g->getSpawnCol() * 600.0f / g->getCols();
    float startY = g->getSpawnRow() * 600.0f / g->getRows() + 16;
    character = Movable(0, 20, ":/img/MainCharacter.png", ui->playerLabel, this->height(), this->width());
    character.setLives(3, ui->lives);
    enemyCharacter = Movable(550, 560, ":/img/Enemy.png", ui->enemyLabel, this->height(), this->width());
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool isSolid(int y, int x) {
    Tile* t = MyGL::getLevelsWrapper()->l->getLevel()->tileAt(y, x);
    if(t == nullptr)
        return true;
    else
        return t->isSolid();
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    float y_inc = 0.0, x_inc = 0.0;

    int x = character.getTileX();
    int y = character.getTileY();

    if (event->key() == Qt::Key_W) {
        if (character.getY() > 20 && isSolid(y - 1, x))
            y_inc = -5.0f;
    }
    if (event->key() == Qt::Key_S) {
        if (character.getY() + 90 < 650 && isSolid(y + 1, x))
            y_inc = 5.0f;
    }
    if (event->key() == Qt::Key_A) {
        if (character.getX() > 0 && isSolid(y, x - 1))
            x_inc = -5.0f;
                //setPos(x()-5,y());
    }
    if (event->key() == Qt::Key_D) {
        if (character.getX() + 100 < 650 && isSolid(y, x + 1))
             x_inc = 5.0f;
    }
    if (event->key() == Qt::Key_Space) {
        bomb = Bomb(0.5, 0.5, character.getX(), character.getY(), ":/img/Utility.png", ui->bombLabel);
        bomb.explode();
        qDebug() << '(' << character.getTileX() << ',' << character.getTileY() << ')';
    }
    character.move(x_inc, y_inc);

    float yMove = 0.0, xMove = 0.0;
        if (event->key() == Qt::Key_Up) {
            if (enemyCharacter.getY() > 0 && isSolid(y - 1, x))
                yMove = -5.0f;
        }
        if (event->key() == Qt::Key_Down) {
            if (enemyCharacter.getY() + 90 < 600 && isSolid(y + 1, x))
                yMove = 5.0f;
        }
        if (event->key() == Qt::Key_Left) {
            if (enemyCharacter.getX() > 0 && isSolid(y, x - 1))
                 xMove = -5.0f;
        }
        if (event->key() == Qt::Key_Right) {
            if (enemyCharacter.getX() + 100 < 650 && isSolid(y, x + 1))
                 xMove = 5.0f;
        }

        enemyCharacter.move(xMove, yMove);
}
