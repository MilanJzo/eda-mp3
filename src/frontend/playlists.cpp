//
// Created by fruit on 03.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_playlists.h" resolved

#include "playlists.h"
#include "ui_playlists.h"


playlists::playlists(QWidget *parent) :
    QWidget(parent), ui(new Ui::playlists) {
    ui->setupUi(this);
}

playlists::~playlists() {
    delete ui;
}
