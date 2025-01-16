//
// Created by fruit on 11.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_editor.h" resolved

#include "editor.h"

#include "editorsong.h"
#include "switcher.h"
#include "ui_editor.h"
#include "../backend/playlistManager.h"


editor::editor(QWidget *parent, const playlist &p, const int index) :
    QWidget(parent), ui(new Ui::editor), index(index), thisPlaylist(p){
    ui->setupUi(this);

    ui->editorTitle->setText(p.getName());

    connect(ui->backButton, &QPushButton::clicked, switcher::getInstance(), &switcher::onBackButtonClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &editor::onDeleteClicked);

    connect(this, &editor::deletePlaylist, playlistManager::getInstance(), &playlistManager::onDeletePlaylist);
    connect(this, &editor::deleteSongFromPlaylist, playlistManager::getInstance(), &playlistManager::onDeleteSongFromPlaylist);
    connect(playlistManager::getInstance(), &playlistManager::playlistsChanged, this, &editor::onPlaylistsChanged);

    renderSongs();
}

void editor::renderSongs()
{
    ui->songList->clear();

    int index = 0;
    for (const song &s : playlistManager::getInstance()->getPlaylists()[index])
    {
        const auto item = new QListWidgetItem(ui->songList);
        const auto songWidget = new editorsong(this, s, index);

        item->setSizeHint(songWidget->sizeHint());

        ui->songList->addItem(item);
        ui->songList->setItemWidget(item, songWidget);
        index++;
    }
}

void editor::onPlaylistsChanged() {
    renderSongs();
    qDebug() << "editor rendered";
}

void editor::onDeleteSongFromPlaylistClicked(const int songIndex) {
    emit deleteSongFromPlaylist(index, songIndex);
    qDebug() << "deleteSongFromPlaylist with songIndex and playlistIndex emitted";
}

void editor::onDeleteClicked() {
    emit deletePlaylist(index);
    ui->backButton->click();
}

editor::~editor() {
    delete ui;
}
