#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "my_gl.h"

#include "draw.h"
#include "vec.h"

#include <QKeyEvent>
#include <QDebug>
#include "movable.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    Movable character(0.5, 0.5, "/home/andy/BombermanUltimate2.png", ui->playerLabel);
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
    character.move(x_inc, y_inc);
}
