//
// Created by fruit on 11.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_editorsong.h" resolved

#include "editorsong.h"

#include <ui_switcher.h>

#include "switcher.h"
#include "ui_editorsong.h"
#include "../backend/playlistManager.h"


editorsong::editorsong(editor *parent, const song &s, const int index) :
    QWidget(parent), ui(new Ui::editorsong), thisSong(s), index(index) {
    ui->setupUi(this);

    ui->cover->setPixmap(s.getCover());
    ui->title->setText(s.getTitle());
    ui->artist->setText(s.getArtist());

    connect(ui->removeFromPlaylist, &QPushButton::clicked, this, &editorsong::onDeleteFromPlaylistClicked);
    connect(this, &editorsong::deleteSongFromPlaylist, parent, &editor::onDeleteSongFromPlaylistClicked);
}

void editorsong::onDeleteFromPlaylistClicked() {
    emit deleteSongFromPlaylist(index);
    qDebug() << "deleteSongFromPlaylist with songIndex emitted";
}

editorsong::~editorsong() {
    delete ui;
}
