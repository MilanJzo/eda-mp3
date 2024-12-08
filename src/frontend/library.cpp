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

    auto manager = libraryManager::getInstance();
    renderSongs(manager->getLibrary());

    connect(manager, libraryManager::libraryChanged, this, &library::on_libraryChanged);
}

void library::on_libraryChanged() {
    renderSongs(libraryManager::getInstance()->getLibrary());
}

void library::renderSongs(QVector<song> songs) {
    ui->songList->clear();

    for (const song &song: songs) {
        const auto item = new QListWidgetItem(ui->songList);
        const auto songWidget = new librarysong(this, song);

        item->setSizeHint(songWidget->sizeHint());

        ui->songList->addItem(item);
        ui->songList->setItemWidget(item, songWidget);
    }
    qDebug() << "Rendered songs";
}

void library::on_addButton_clicked() const
{
    libraryManager::getInstance()->addDirectory();
}

library::~library() {
    delete ui;
}