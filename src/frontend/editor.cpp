//
// Created by fruit on 11.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_editor.h" resolved

#include "editor.h"

#include "editorsong.h"
#include "switcher.h"
#include "ui_editor.h"
#include "../backend/playlistManager.h"


editor::editor(QWidget *parent, const int playlistIndex):
    QWidget(parent), ui(new Ui::editor), playlistIndex(playlistIndex) {
    ui->setupUi(this);

    ui->editorTitle->setText(playlistManager::getInstance()->getPlaylists()[playlistIndex].getName());

    connect(ui->backButton, &QPushButton::clicked, switcher::getInstance(), &switcher::onBackButtonClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &editor::onDeleteClicked);

    connect(this, &editor::deletePlaylist, playlistManager::getInstance(), &playlistManager::onDeletePlaylist);
    connect(this, &editor::deleteSongFromPlaylist, playlistManager::getInstance(), &playlistManager::onDeleteSongFromPlaylist);
    connect(playlistManager::getInstance(), &playlistManager::playlistsChanged, this, &editor::onPlaylistsChanged);

    renderSongs();
}

//renders all song widgets in the editor window
void editor::renderSongs() {
    ui->songList->clear();

    if (isPlaylistDeleted)
    {
        return;
    }
    auto playlist = playlistManager::getInstance()->getPlaylists()[playlistIndex];


    int index = 0;
    for (const song &s : playlist)
    {
        const auto item = new QListWidgetItem(ui->songList);
        const auto songWidget = new editorsong(this, s, index);

        item->setSizeHint(songWidget->sizeHint());

        ui->songList->addItem(item);
        ui->songList->setItemWidget(item, songWidget);
        index++;
    }
}

//calls renderSongs function when playlist changed
void editor::onPlaylistsChanged() {
    renderSongs();
}

//emits deleteSongFromPlaylist with the song index when the delete button is clicked
void editor::onDeleteSongFromPlaylistClicked(const int songIndex) {
    emit deleteSongFromPlaylist(playlistIndex, songIndex);
}

//deletes the playlist, changes existing status of playlist and switches back to the library window
void editor::onDeleteClicked() {
    isPlaylistDeleted = true;
    emit deletePlaylist(playlistIndex);
    ui->backButton->click();
}

editor::~editor() {
    delete ui;
}
