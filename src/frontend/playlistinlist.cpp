//
// Created by fruit on 11.12.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_playlistinlist.h" resolved

#include "playlistinlist.h"
#include "ui_playlistinlist.h"


playlistinlist::playlistinlist(QWidget *parent, const QString &name) :
    QWidget(parent), ui(new Ui::playlistinlist) {
    ui->setupUi(this);

    ui->name->setText(name);
    ui->cover->setPixmap(QPixmap(":/image/placeholder.png").scaled(48, 48));
}

playlistinlist::~playlistinlist() {
    delete ui;
}
