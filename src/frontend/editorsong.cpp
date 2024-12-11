//
// Created by fruit on 11.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_editorsong.h" resolved

#include "editorsong.h"
#include "ui_editorsong.h"


editorsong::editorsong(QWidget *parent, const song &s) :
    QWidget(parent), ui(new Ui::editorsong), thisSong(s) {
    ui->setupUi(this);

    ui->cover->setPixmap(s.getCover());
    ui->title->setText(s.getTitle());
    ui->artist->setText(s.getArtist());
}

editorsong::~editorsong() {
    delete ui;
}
