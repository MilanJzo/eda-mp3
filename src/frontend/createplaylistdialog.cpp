//
// Created by fruit on 10.12.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_createplaylistdialog.h" resolved

#include "createplaylistdialog.h"

#include <QFileDialog>

#include "ui_createplaylistdialog.h"
#include "../backend/playlistManager.h"


createplaylistdialog::createplaylistdialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::createplaylistdialog) {
    ui->setupUi(this);

    connect(ui->create, &QPushButton::clicked, this, &createplaylistdialog::onCreateClicked);
    connect(ui->chooseCover, &QPushButton::clicked, this, &createplaylistdialog::onChooseCoverClicked);
}

void createplaylistdialog::onCreateClicked() {
    const auto playlistName = ui->playlistName->text();

    if (playlistName.isEmpty()) {
        qWarning() << "Playlist Name cant be empty";
        return;
    }

    playlistManager::getInstance()->createPlaylist(playlistName, QUrl());

    close();
}

void createplaylistdialog::onChooseCoverClicked() {
    const auto coverPath = QFileDialog::getOpenFileName(this, "Choose cover", QDir::homePath(), "Images (*.png *.jpg)");
    ui->coverUrl->setText(coverPath);
}

createplaylistdialog::~createplaylistdialog() {
    delete ui;
}
