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

    connect(libraryManager::getInstance(), &libraryManager::libraryChanged, this, &library::on_libraryChanged);
}

void library::on_libraryChanged() {
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
    qDebug() << "Rendered Library";
}

void library::on_addButton_clicked() const
{
    libraryManager::getInstance()->addDirectory();
}

library::~library() {
    delete ui;
}