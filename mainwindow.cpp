#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "my_gl.h"

#include "draw.h"
#include "vec.h"

#include <QKeyEvent>
#include <QDebug>
#include "movable.h"
#include "bomb.h"

Movable character;
Bomb bomb;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    character = Movable(0, 0, ":/img/BombermanUltimate2.png", ui->playerLabel);
    character.setLives(3, ui->lives);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    float y_inc = 0.0, x_inc = 0.0;

    if (event->key() == Qt::Key_W) {
        y_inc = -5.0f;
    }
    if (event->key() == Qt::Key_S) {
        y_inc = 5.0f;
    }
    if (event->key() == Qt::Key_A) {
        x_inc = -5.0f;
    }
    if (event->key() == Qt::Key_D) {
        x_inc = 5.0f;
    }
    if (event->key() == Qt::Key_Space) {
        bomb = Bomb(0.5, 0.5, character.getX(), character.getY(), ":/img/Bomb.png", ui->BombLabel);
        bomb.explode();
    }
    character.move(x_inc, y_inc);
}
