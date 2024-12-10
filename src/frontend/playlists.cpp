//
// Created by fruit on 03.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_playlists.h" resolved

#include "playlists.h"

#include "createplaylistdialog.h"
#include "ui_playlists.h"
#include "../backend/playlistManager.h"


playlists::playlists(QWidget *parent) :
    QWidget(parent), ui(new Ui::playlists) {
    ui->setupUi(this);

    renderPlaylists();

    connect(ui->addButton, &QPushButton::clicked, this, &playlists::onAddButtonClicked);
    connect(playlistManager::getInstance(), &playlistManager::playistsChanged, this, &playlists::onPlaylistsChanged);
}

void playlists::onPlaylistsChanged() {
    renderPlaylists();
}

void playlists::renderPlaylists() {
    ui->playlistList->clear();

    for (const auto& playlist: playlistManager::getInstance()->getPlaylists()) {
        ui->playlistList->addItem(playlist.getName());
    }
}


void playlists::onAddButtonClicked() {
    const auto createDialog = new createplaylistdialog(this);

    createDialog->exec();
}

playlists::~playlists() {
    delete ui;
}
