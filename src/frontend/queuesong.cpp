//
// Created by fruit on 08.12.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_queueSong.h" resolved

#include "queuesong.h"
#include "ui_queueSong.h"
#include "../backend/queueManager.h"


queueSong::queueSong(QWidget *parent, const song &s, const int index) :
    QWidget(parent), ui(new Ui::queueSong), thisSong(s), index(index) {
    ui->setupUi(this);

    ui->cover->setPixmap(QPixmap::fromImage(s.getCover()));
    ui->title->setText(s.getTitle());
    ui->artist->setText(s.getArtist());

    connect(ui->removeFromQueue, QPushButton::clicked, this, &queueSong::onRemoveFromQueueClicked);
    connect(this, removeFromQueue, queueManager::getInstance(), &queueManager::onRemoveFromQueue);
}

void queueSong::onRemoveFromQueueClicked() {
    emit removeFromQueue(index);
}

queueSong::~queueSong() {
    delete ui;
}
