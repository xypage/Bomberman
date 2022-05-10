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

    character = Movable(0, 20, ":/img/MainCharacter.png", ui->playerLabel, this->height(), this->width());
    character.setLives(3, ui->lives);
    enemyCharacter = Movable(515, 530, ":/img/Enemy.png", ui->enemyLabel, this->height(), this->width());
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString checkCollision(Tile* t) {
    if(t == nullptr)
        return "Null";
    QString qs = "";
    if(t->isSolid())
        qs += "Solid ";
    else
        qs += "Empty ";

    if(t->isBreakable())
        qs += "Breakable";
    else
        qs += "Invincible";

    return qs;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    float y_inc = 0.0, x_inc = 0.0;

    if (event->key() == Qt::Key_W) {
        if (character.getY() > 18)
            y_inc = -5.0f;
    }
    if (event->key() == Qt::Key_S) {
        if (character.getY() + 90 < 620)
            y_inc = 5.0f;
    }
    if (event->key() == Qt::Key_A) {
        if (character.getX() > 0)
            x_inc = -5.0f;
                //setPos(x()-5,y());
    }
    if (event->key() == Qt::Key_D) {
        if (character.getX() + 100 < 615)
             x_inc = 5.0f;
    }
    if (event->key() == Qt::Key_Space) {
        bomb = Bomb(0.5, 0.5, character.getX(), character.getY(), ":/img/Utility.png", ui->bombLabel);
        bomb.explode();
        qDebug() << '(' << character.getTileX() << ',' << character.getTileY() << ')';
    }

    int x = character.getTileX();
    int y = character.getTileY();
    if (event->key() == Qt::Key_Up) {
        qDebug() << "x: " << x << "y:" << y - 1 << "state: " << checkCollision(MyGL::getLevelsWrapper()->l->getLevel()->tileAt(y - 1, x));
    }
    if (event->key() == Qt::Key_Down) {
        qDebug() << "x: " << x << "y:" << y + 1 << "state: " << checkCollision(MyGL::getLevelsWrapper()->l->getLevel()->tileAt(y + 1, x));
    }
    if (event->key() == Qt::Key_Left) {
        qDebug() << "x: " << x - 1 << "y:" << y << "state: " << checkCollision(MyGL::getLevelsWrapper()->l->getLevel()->tileAt(y, x - 1));
    }
    if (event->key() == Qt::Key_Right) {
        qDebug() << "x: " << x + 1 << "y:" << y << "state: " << checkCollision(MyGL::getLevelsWrapper()->l->getLevel()->tileAt(y, x + 1));
    }
    character.move(x_inc, y_inc);
}
