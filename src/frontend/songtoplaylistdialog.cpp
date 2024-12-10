//
// Created by Markus on 10.12.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_songToPlaylistDialog.h" resolved

#include "songtoplaylistdialog.h"
#include "ui_songToPlaylistDialog.h"

songToPlaylistDialog *songToPlaylistDialog::instance = nullptr;

songToPlaylistDialog::songToPlaylistDialog(QWidget *parent) : QDialog(parent), ui(new Ui::songToPlaylistDialog) {
    ui->setupUi(this);
}

songToPlaylistDialog* songToPlaylistDialog::getInstance() {
    if (instance == nullptr) { instance = new songToPlaylistDialog(); }
    return instance;
}

void songToPlaylistDialog::onAddToPlaylist(const song &s) {
    exec();
}


songToPlaylistDialog::~songToPlaylistDialog() {
    delete ui;
}