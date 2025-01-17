//
// Created by fruit on 11.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_editor.h" resolved

#include "editor.h"

#include "editorsong.h"
#include "switcher.h"
#include "ui_editor.h"
#include "../backend/playlistManager.h"


editor::editor(QWidget *parent, const playlist &p, const int playlistIndex) :
    QWidget(parent), ui(new Ui::editor), playlistIndex(playlistIndex), thisPlaylist(p){
    ui->setupUi(this);

    ui->editorTitle->setText(p.getName());

    connect(ui->backButton, &QPushButton::clicked, switcher::getInstance(), &switcher::onBackButtonClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &editor::onDeleteClicked);

    connect(this, &editor::deletePlaylist, playlistManager::getInstance(), &playlistManager::onDeletePlaylist);

    renderSongs();
}

void editor::renderSongs() {
    for (const song &s : thisPlaylist)
    {
        const auto item = new QListWidgetItem(ui->songList);
        const auto songWidget = new editorsong(this, s);

        item->setSizeHint(songWidget->sizeHint());

        ui->songList->addItem(item);
        ui->songList->setItemWidget(item, songWidget);
    }
}

void editor::onDeleteClicked() {
    qDebug() << "editor -> onDeleteClicked: " + std::to_string(playlistIndex);
    emit deletePlaylist(playlistIndex);
    ui->backButton->click();
}

editor::~editor() {
    delete ui;
}
