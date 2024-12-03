#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "controls.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->controlsHolder->layout()->addWidget(new controls(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}
