//
// Created by fruit on 05.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_librarysong.h" resolved

#include "librarysong.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "queuesong.h"
#include "ui_librarysong.h"
#include "../backend/player.h"
#include "../backend/playlistManager.h"
#include "../backend/queueManager.h"


librarysong::librarysong(QWidget *parent, const song &s) :
    QWidget(parent), ui(new Ui::librarysong), thisSong(s) {

    ui->setupUi(this);

    ui->cover->setPixmap(s.getCover());
    ui->title->setText(s.getTitle());
    ui->artist->setText(s.getArtist());
    ui->time->setText(" - " + s.getDuration());

    connect(ui->playDirectly, &QPushButton::clicked, this, &librarysong::onPlayDirectlyClicked);
    connect(this, &librarysong::playDirectly, queueManager::getInstance(), &queueManager::onPlayDirectly);

    connect(ui->addToQueue, &QPushButton::clicked, this, &librarysong::onAddToQueueClicked);
    connect(this, &librarysong::addToQueue, queueManager::getInstance(), &queueManager::onAddToQueue);

    connect(ui->addToPlaylist, &QPushButton::clicked, this, &librarysong::onAddToPlaylistClicked);
}

//emits playDirectly with the song object when the play button is clicked
void librarysong::onPlayDirectlyClicked() const {
    emit playDirectly(thisSong);
}

//emits addToQueue with the song object when the add to queue button is clicked
void librarysong::onAddToQueueClicked() const {
    emit addToQueue(thisSong);
}

//opens a dialog window to add the song to a playlist when the add to playlist button is clicked
void librarysong::onAddToPlaylistClicked() {
    const auto addDialog = new addtoplaylistdialog(this, thisSong);

    addDialog->exec();
}

librarysong::~librarysong() {
    delete ui;
}