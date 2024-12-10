//
// Created by Markus on 10.12.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_songToPlaylistDialog.h" resolved

#include "songtoplaylistdialog.h"

#include "addtoplaylist.h"
#include "ui_songToPlaylistDialog.h"
#include "../backend/libraryManager.h"
#include "../backend/playlistManager.h"

songToPlaylistDialog *songToPlaylistDialog::instance = nullptr;

songToPlaylistDialog::songToPlaylistDialog(QWidget *parent) : QDialog(parent), ui(new Ui::songToPlaylistDialog), s(s) {
    ui->setupUi(this);

    connect(playlistManager::getInstance(), &playlistManager::playlistsChanged, this, &songToPlaylistDialog::onPlaylistChanged);
    renderPlaylists();
}

songToPlaylistDialog* songToPlaylistDialog::getInstance() {
    if (instance == nullptr) { instance = new songToPlaylistDialog(); }
    return instance;
}

void songToPlaylistDialog::onAddToPlaylist(const song& s) {
    exec();
    this->s = s;
}

void songToPlaylistDialog::onPlaylistChanged() {
    renderPlaylists();
}

void songToPlaylistDialog::renderPlaylists() {
    ui->playlists->clear();
    auto playlists = playlistManager::getInstance()->getPlaylists();
    for (auto &playlist : playlists) {
        const auto item = new QListWidgetItem(ui->playlists);
        const auto playlistWidget = new addtoplaylist(this, playlist.getName(), s);

        item->setSizeHint(playlistWidget->sizeHint());

        ui->playlists->addItem(item);
        ui->playlists->setItemWidget(item, playlistWidget);
    }
}

songToPlaylistDialog::~songToPlaylistDialog() {
    delete ui;
}