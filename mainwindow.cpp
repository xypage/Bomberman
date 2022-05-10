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
    this->setFixedSize(QSize(600, 616));

    character = Movable(0, 0, ":/img/MainCharacter.png", ui->playerLabel, this->height(), this->width());
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
        if (character.getY() > 10)
            y_inc = -5.0f;
            character.getTileX();
    }
    if (event->key() == Qt::Key_S) {
        if (character.getY() + 90 < 595)
            y_inc = 5.0f;
    }
    if (event->key() == Qt::Key_A) {
        if (character.getX() > -20)
            x_inc = -5.0f;
    }
    if (event->key() == Qt::Key_D) {
        if (character.getX() + 100 < 615)
             x_inc = 5.0f;
    }
    if (event->key() == Qt::Key_Space) {
        bomb = Bomb(0.5, 0.5, character.getX(), character.getY(), ":/img/Utility.png", ui->bombLabel);
        bomb.explode();
    }
    character.move(x_inc, y_inc);
}
