//
// Created by fruit on 06.12.2024.
//

#include "song.h"

#include <utility>

song::song(
    QUrl url,
    QString title,
    QString artist
    ) :
url(std::move(url)),
title(std::move(title.slice(0, title.lastIndexOf('.')))),
artist(std::move(artist)) {

}

song::~song() = default;