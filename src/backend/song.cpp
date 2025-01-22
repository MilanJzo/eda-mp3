//
// Created by fruit on 06.12.2024.
//

#include "song.h"

#include <utility>

//defines a song object
song::song(
    QUrl url,
    const QPixmap& cover,
    QString title,
    QString artist,
    QString duration
    ) :
url(std::move(url)),
cover(std::move(cover.scaled(55, 55, Qt::IgnoreAspectRatio, Qt::SmoothTransformation))),
title(std::move(title)),
artist(std::move(artist)),
duration(std::move(duration)){
    id = QUuid::createUuid();
}


song::~song() = default;