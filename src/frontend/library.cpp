//
// Created by Markus Heming on 03.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_library.h" resolved

#include "library.h"
#include "librarysong.h"

#include <QMediaPlayer>
#include <QMediaMetaData>

#include "ui_library.h"
#include "../backend/libraryManager.h"



library::library(QWidget *parent) :
    QWidget(parent), ui(new Ui::library) {
    ui->setupUi(this);

    manager = libraryManager::getInstance();
    renderSongs(manager->getLibrary());
}

void library::renderSongs(const QVector<song> &songs) {
    for (auto &song: songs) {
        const auto item = new QListWidgetItem(ui->songList);
        const auto songWidget = new librarysong(this, song.getTitle(), song.getArtist());
        item->setSizeHint(songWidget->sizeHint());

        ui->songList->addItem(item);
        ui->songList->setItemWidget(item, songWidget);
    }
    qDebug() << "Rendered songs";
}

void library::on_addButton_clicked() const
{
    manager->addDirectory();
}

library::~library() {
    delete ui;
}