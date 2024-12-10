//
// Created by fruit on 10.12.2024.
//

#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <qcontainerfwd.h>

#include "song.h"

class playlist : public QVector<song>{
public:
    playlist();
    [[nodiscard]] QUuid getId() const { return id; }
    [[nodiscard]] QString getName() const { return name; }

    void setName(const QString &newName) { name = newName; }

private:
    QUuid id;
    QString name;
};

#endif //PLAYLIST_H
