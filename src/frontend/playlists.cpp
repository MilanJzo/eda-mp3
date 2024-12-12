//
// Created by fruit on 03.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_playlists.h" resolved

#include "playlists.h"

#include "createplaylistdialog.h"
#include "playlistinlist.h"
#include "ui_playlists.h"
#include "../backend/playlistManager.h"


playlists::playlists(QWidget *parent) :
    QWidget(parent), ui(new Ui::playlists) {
    ui->setupUi(this);

    renderPlaylists();

    connect(ui->addButton, &QPushButton::clicked, this, &playlists::onAddButtonClicked);
    connect(playlistManager::getInstance(), &playlistManager::playlistsChanged, this, &playlists::onPlaylistsChanged);
}

void playlists::onPlaylistsChanged() {
    renderPlaylists();
}

void playlists::renderPlaylists() {
    ui->playlistList->clear();

    int index = 0;
    for (const auto& playlist: playlistManager::getInstance()->getPlaylists()) {
        const auto item = new QListWidgetItem(ui->playlistList);
        const auto playlistWidget = new playlistinlist(this, playlist, index);

        item->setSizeHint(playlistWidget->sizeHint());

        ui->playlistList->addItem(item);
        ui->playlistList->setItemWidget(item, playlistWidget);
        index++;
    }
}


void playlists::onAddButtonClicked() {
    const auto createDialog = new createplaylistdialog(this);

    createDialog->exec();
}

playlists::~playlists() {
    delete ui;
}
