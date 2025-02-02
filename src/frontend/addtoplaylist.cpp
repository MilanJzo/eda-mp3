//
// Created by fruit on 11.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_addtoplaylist.h" resolved

#include "addtoplaylist.h"
#include "ui_addtoplaylist.h"
#include "../backend/playlistManager.h"


addtoplaylist::addtoplaylist(QWidget *parent, QString name, const song &s) :
    QWidget(parent), ui(new Ui::addtoplaylist), thisSong(s) {
    ui->setupUi(this);

    ui->name->setText(name);

    connect(ui->add, &QPushButton::clicked, this, &addtoplaylist::onAddClicked);
}

//button click event in song popup to add song to playlist
void addtoplaylist::onAddClicked()
{
    playlistManager::getInstance()->addTrackToPlaylist(ui->name->text(), thisSong);
}

addtoplaylist::~addtoplaylist() {
    delete ui;
}
