#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "my_gl.h"

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
