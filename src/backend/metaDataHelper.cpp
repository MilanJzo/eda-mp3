//
// Created by fruit on 09.12.2024.
//

#include "metaDataHelper.h"

#include <QMediaMetaData>

metaDataHelper::metaDataHelper(QObject *parent, const player *player) : QObject(parent)
{
    connect(player, player::metaDataChanged, this, &metaDataHelper::onMetaDataChanged);
}

void metaDataHelper::onMetaDataChanged()
{
    qDebug() << "detected metadata change";
    const auto metadata = player::getInstance()->metaData();

    const auto cover = metadata.value(QMediaMetaData::ThumbnailImage).value<QPixmap>();
    const auto title = metadata.value(QMediaMetaData::Title).toString();
    const auto artist = metadata.value(QMediaMetaData::ContributingArtist).toString();

    m_songs.append(song(QUrl(), cover, title, artist));
}