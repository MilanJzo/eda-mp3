//
// Created by fruit on 11.12.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_playlistinlist.h" resolved

#include "playlistinlist.h"

#include "mainwindow.h"
#include "switcher.h"
#include "ui_playlistinlist.h"
#include "../backend/queueManager.h"


playlistinlist::playlistinlist(QWidget *parent, const playlist &p, const int index) :
    QWidget(parent), ui(new Ui::playlistinlist), thisPlaylist(p), index(index)
{
    ui->setupUi(this);

    ui->name->setText(p.getName());
    ui->cover->setPixmap(QPixmap(":/image/placeholder.png").scaled(48, 48));

    connect(ui->playDirectly, &QPushButton::clicked, this, &playlistinlist::onPlayDirectlyClicked);
    connect(this, &playlistinlist::playPlaylistDirectly, queueManager::getInstance(), &queueManager::onPlayPlaylistDirectly);

    connect(ui->addToQueue, &QPushButton::clicked, this, &playlistinlist::onQueuePlaylistClicked);
    connect(this, &playlistinlist::queuePlaylist, queueManager::getInstance(), &queueManager::onQueuePlaylist);

    connect(ui->edit, &QPushButton::clicked, this, &playlistinlist::onEditPlaylistClicked);
    connect(this, &playlistinlist::editPlaylist, switcher::getInstance(), &switcher::onEditPlaylist);
}

void playlistinlist::onPlayDirectlyClicked() {
    emit playPlaylistDirectly(thisPlaylist);
}

void playlistinlist::onQueuePlaylistClicked() {
    emit queuePlaylist(thisPlaylist);
}

void playlistinlist::onEditPlaylistClicked() {
    // qDebug() << "Edit Playlist clicked " + index;
    qDebug() << " playlistinlist -> Edit Playlist clicked " + std::to_string(index);
    emit editPlaylist(thisPlaylist, index);
}

playlistinlist::~playlistinlist() {
    delete ui;
}
