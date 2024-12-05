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

#include <taglib/fileref.h>
#include <taglib/tag.h>

library::library(QWidget *parent) :
    QWidget(parent), ui(new Ui::library) {
    ui->setupUi(this);

    manager = libraryManager::getInstance();
    renderSongs(manager->getLibrary());
}

void library::renderSongs(const QStringList &songs) {
    QMediaPlayer temporaryPlayer;
    foreach (const QString &song, songs)
    {
        // temporaryPlayer.setSource(QUrl::fromLocalFile(song));
        // QMediaMetaData metaData = temporaryPlayer.metaData();
        // QString title = metaData.value(QMediaMetaData::Title).toString();
        // QString artist = metaData.value(QMediaMetaData::Author).toString();

        qDebug() << "Rendering song: " << song;
        TagLib::FileRef file((song.toStdString().c_str()));
        QString title = file.tag()->title().toCString(true);
        QString artist = file.tag()->artist().toCString(true);

        ui->scrollArea->layout()->addWidget(new librarysong(this, title, artist));
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