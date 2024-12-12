//
// Created by Markus Heming on 03.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_library.h" resolved

#include "library.h"
#include "librarysong.h"

#include <QMediaMetaData>

#include <QMenu>
#include "ui_library.h"
#include "../backend/libraryManager.h"
#include "../backend/playlistManager.h"


library::library(QWidget *parent) :
    QWidget(parent), ui(new Ui::library) {
    ui->setupUi(this);

    renderSongs();

    connect(libraryManager::getInstance(), &libraryManager::libraryChanged, this, &library::onLibraryChanged);
    connect(ui->addButton, &QPushButton::clicked, this, &library::onAddButtonClicked);
}

void library::onLibraryChanged() {
    renderSongs();
}

void library::renderSongs() {
    ui->songList->clear();

    const auto library = libraryManager::getInstance()->getLibrary();
    for (const song &song: library) {
        const auto item = new QListWidgetItem(ui->songList);
        const auto songWidget = new librarysong(this, song);

        item->setSizeHint(songWidget->sizeHint());

        ui->songList->addItem(item);
        ui->songList->setItemWidget(item, songWidget);
    }
}

void library::onAddButtonClicked() const
{
    libraryManager::getInstance()->addDirectory();
}

library::~library() {
    delete ui;
}