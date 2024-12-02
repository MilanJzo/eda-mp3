//
// Created by fruit on 02.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_controls.h" resolved

#include "controls.h"
#include "ui_controls.h"


controls::controls(QWidget *parent) :
    QWidget(parent), ui(new Ui::controls) {
    ui->setupUi(this);
}

controls::~controls() {
    delete ui;
}
