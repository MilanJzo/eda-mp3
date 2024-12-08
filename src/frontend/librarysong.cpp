//
// Created by fruit on 05.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_librarysong.h" resolved

#include "librarysong.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "ui_librarysong.h"
#include "../backend/player.h"
#include "../backend/queueManager.h"


librarysong::librarysong(QWidget *parent, const song &s) :
    QWidget(parent), ui(new Ui::librarysong), thisSong(s) {

    ui->setupUi(this);

    ui->cover->setPixmap(QPixmap::fromImage(s.getCover()));
    ui->title->setText(s.getTitle());
    ui->artist->setText(s.getArtist());

    connect(ui->playDirectly, QPushButton::clicked, this, &librarysong::onPlayDirectlyClicked);
}

librarysong::~librarysong() {
    delete ui;
}

void librarysong::onPlayDirectlyClicked() const {
    // player *Player = player::getInstance();
    // Player->setSource(thisSong.getUrl().toString());
    // Player->play();

    queueManager *QueueManager = queueManager::getInstance();
    QueueManager->prepend(thisSong);
}

