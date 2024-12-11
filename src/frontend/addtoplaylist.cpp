//
// Created by fruit on 11.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_addtoplaylist.h" resolved

#include "addtoplaylist.h"
#include "ui_addtoplaylist.h"


addtoplaylist::addtoplaylist(QWidget *parent, QString name) :
    QWidget(parent), ui(new Ui::addtoplaylist) {
    ui->setupUi(this);

    ui->name->setText(name);
}

addtoplaylist::~addtoplaylist() {
    delete ui;
}
