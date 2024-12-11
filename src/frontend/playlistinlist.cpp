//
// Created by fruit on 11.12.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_playlistinlist.h" resolved

#include "playlistinlist.h"
#include "ui_playlistinlist.h"
#include "../backend/queueManager.h"


playlistinlist::playlistinlist(QWidget *parent, const playlist &p) :
    QWidget(parent), ui(new Ui::playlistinlist), thisPlaylist(p)
{
    ui->setupUi(this);

    ui->name->setText(p.getName());
    ui->cover->setPixmap(QPixmap(":/image/placeholder.png").scaled(48, 48));

    connect(ui->playDirectly, &QPushButton::clicked, this, &playlistinlist::onPlayDirectlyClicked);
    connect(this, &playlistinlist::playPlaylistDirectly, queueManager::getInstance(), &queueManager::onPlayPlaylistDirectly);
}

void playlistinlist::onPlayDirectlyClicked() {
    emit playPlaylistDirectly(thisPlaylist);
}

playlistinlist::~playlistinlist() {
    delete ui;
}
