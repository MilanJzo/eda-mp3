//
// Created by fruit on 10.12.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_addtoplaylist.h" resolved

#include "addtoplaylist.h"

#include "songtoplaylistdialog.h"
#include "ui_addtoplaylist.h"
#include "../backend/playlistManager.h"


addtoplaylist::addtoplaylist(QWidget *parent, QString name, const song &s) :
QWidget(parent), ui(new Ui::addtoplaylist), s(s) {
    ui->setupUi(this);

    ui->playlistName->setText(name);

    connect(ui->select, &QPushButton::clicked, this, &addtoplaylist::onSelectClicked);
}

void addtoplaylist::onSelectClicked() {
    const QString name = ui->playlistName->text();
    qDebug() << "Selected playlist: " << name;
    // playlistManager::getInstance()->addTrackToPlaylist(name, s);
    close();
}

addtoplaylist::~addtoplaylist() {
    delete ui;
}
