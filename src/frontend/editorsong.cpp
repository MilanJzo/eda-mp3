//
// Created by fruit on 11.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_editorsong.h" resolved

#include "editorsong.h"
#include "ui_editorsong.h"


editorsong::editorsong(QWidget *parent) :
    QWidget(parent), ui(new Ui::editorsong) {
    ui->setupUi(this);
}

editorsong::~editorsong() {
    delete ui;
}
