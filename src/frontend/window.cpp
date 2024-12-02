//
// Created by fruit on 02.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_window.h" resolved

#include "window.h"
#include "ui_window.h"

window::window(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::window)
{
    ui->setupUi(this);
}

window::~window() {
    delete ui;
}
