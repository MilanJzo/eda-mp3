//
// Created by fruit on 06.12.2024.
//

#include "song.h"

song::song(
    QUrl url,
    QPixmap cover,
    QString title,
    QString artist
    ) :
url(std::move(url)),
cover(std::move(cover.scaled(55, 55))),
title(title.chopped(4)),
artist(std::move(artist)) {
    id = QUuid::createUuid();
}

song::~song() = default;