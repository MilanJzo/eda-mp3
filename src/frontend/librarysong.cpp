//
// Created by fruit on 05.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_librarysong.h" resolved

#include "librarysong.h"
#include "ui_librarysong.h"


librarysong::librarysong(QWidget *parent, const QString &title, const QString &artist) :
    QWidget(parent), ui(new Ui::librarysong) {
    ui->setupUi(this);
    ui->title->setText(title);
    ui->artist->setText(artist);
}

librarysong::~librarysong() {
    delete ui;
}
