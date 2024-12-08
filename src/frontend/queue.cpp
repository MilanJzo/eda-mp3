//
// Created by fruit on 03.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_queue.h" resolved

#include "queue.h"
#include "ui_queue.h"


queue::queue(QWidget *parent) :
    QWidget(parent), ui(new Ui::queue) {
    ui->setupUi(this);
}

queue::~queue() {
    delete ui;
}
