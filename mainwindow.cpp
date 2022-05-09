#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "my_gl.h"

#include "draw.h"
#include "vec.h"

#include <QKeyEvent>
#include <QDebug>


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
    float yMove = ui->playerLabel->y();
    float xMove = ui->playerLabel->x();
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

    ui->playerLabel->move(QPoint(xMove + x_inc, yMove + y_inc));
}
