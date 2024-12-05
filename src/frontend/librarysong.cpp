//
// Created by fruit on 05.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_librarysong.h" resolved

#include "librarysong.h"
#include "ui_librarysong.h"


librarysong::librarysong(QWidget *parent) :
    QWidget(parent), ui(new Ui::librarysong) {
    ui->setupUi(this);
}

librarysong::~librarysong() {
    delete ui;
}
