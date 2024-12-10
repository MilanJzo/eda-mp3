//
// Created by fruit on 10.12.2024.
//

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "song.h"
#include <QVector>

class playlist : public QVector<song>{
public:
    explicit playlist(QString name) : name(std::move(name)) { id = QUuid::createUuid(); }

    void appendRef(const song &s) { this->append(s); }

    [[nodiscard]] QUuid getId() const { return id; }
    [[nodiscard]] QString getName() const { return name; }

    void setName(const QString &newName) { name = newName; }

private:
    QUuid id;
    QString name;
};

#endif //PLAYLIST_H
