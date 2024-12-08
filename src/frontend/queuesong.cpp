//
// Created by fruit on 08.12.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_queueSong.h" resolved

#include "queuesong.h"
#include "ui_queueSong.h"


queueSong::queueSong(QWidget *parent, const song &s) :
    QWidget(parent), ui(new Ui::queueSong), thisSong(s) {
    ui->setupUi(this);

    ui->cover->setPixmap(QPixmap::fromImage(s.getCover()));
    ui->title->setText(s.getTitle());
    ui->artist->setText(s.getArtist());

    connect(ui->removeFromQueue, QPushButton::clicked, this, &queueSong::onRemoveFromQueueClicked);
}

void queueSong::onRemoveFromQueueClicked() {
    emit removeFromQueue(thisSong);
}

queueSong::~queueSong() {
    delete ui;
}
