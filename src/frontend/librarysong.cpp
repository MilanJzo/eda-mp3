//
// Created by fruit on 05.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_librarysong.h" resolved

#include "librarysong.h"
#include "ui_librarysong.h"
#include "../backend/player.h"


librarysong::librarysong(QWidget *parent, const song &s) :
    QWidget(parent), ui(new Ui::librarysong), thisSong(s) {

    ui->setupUi(this);

    ui->title->setText(s.getTitle());
    ui->artist->setText(s.getArtist());

    connect(ui->playDirectly, &QPushButton::clicked, this, &librarysong::on_playDirectly_clicked);
}

librarysong::~librarysong() {
    delete ui;
}

void librarysong::on_playDirectly_clicked() const {
    qDebug() << "Playing song directly";

    player *player = player::getInstance();
    player->setSong(thisSong.getUrl().toString());
    player->togglePlay();

    qDebug() << "Playing song: " << thisSong.getTitle();
}

