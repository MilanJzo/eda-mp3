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

    renderSongs();

    connect(libraryManager::getInstance(), libraryManager::libraryChanged, this, &library::onLibraryChanged);
}

void library::onLibraryChanged() {
    renderSongs();
}

void library::renderSongs() {
    auto songs = libraryManager::getInstance()->getLibrary();

    ui->songList->clear();

    for (song song: songs) {
        const auto item = new QListWidgetItem(ui->songList);
        const auto songWidget = new librarysong(this, &song);

        item->setSizeHint(songWidget->sizeHint());

        ui->songList->addItem(item);
        ui->songList->setItemWidget(item, songWidget);
    }
    qDebug() << "Rendered Library";
}

void library::onAddButtonClicked() const
{
    libraryManager::getInstance()->addDirectory();
}

library::~library() {
    delete ui;
}