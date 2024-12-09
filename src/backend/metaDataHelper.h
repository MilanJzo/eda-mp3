//
// Created by fruit on 09.12.2024.
//

#ifndef METADATAHELPER_H
#define METADATAHELPER_H

#include <QObject>

#include "player.h"
#include "song.h"

class metaDataHelper final : public QObject
{
    Q_OBJECT
public:
    explicit metaDataHelper(QObject *parent = nullptr, const player *player = player::getInstance());
    ~metaDataHelper() override = default;
    [[nodiscard]] QVector<song> getMetaData() { return m_songs; }

private slots:
    void onMetaDataChanged();

private:
    QVector<song> m_songs;

};

#endif //METADATAHELPER_H
