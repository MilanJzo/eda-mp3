//
// Created by fruit on 11.12.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_playlistinlist.h" resolved

#include "playlistinlist.h"
#include "ui_playlistinlist.h"


playlistinlist::playlistinlist(QWidget *parent, QString name) :
    QWidget(parent), ui(new Ui::playlistinlist) {
    ui->setupUi(this);

    ui->name->setText(name);
}

playlistinlist::~playlistinlist() {
    delete ui;
}
