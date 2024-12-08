//
// Created by fruit on 06.12.2024.
//

#include "song.h"

#include <utility>

song::song(
    QUrl url,
    QImage cover,
    QString title,
    QString artist
    ) :
url(std::move(url)),
cover(std::move(cover.scaled(55, 55))),
title(std::move(title.slice(0, title.lastIndexOf('.')))),
artist(std::move(artist)) {
    id = QUuid::createUuid();
}

song::~song() = default;