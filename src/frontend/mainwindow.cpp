#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "controls.h"
#include "library.h"
#include "playlists.h"
#include "queue.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->controlsHolder->layout()->addWidget(new controls(this));
    ui->libraryEditorHolder->layout()->addWidget(new library(this));
    ui->playlistHolder->layout()->addWidget(new playlists(this));
    ui->queueHolder->layout()->addWidget(new queue(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}
