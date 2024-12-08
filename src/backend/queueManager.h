//
// Created by fruit on 08.12.2024.
//

#ifndef QUEUEMANAGER_H
#define QUEUEMANAGER_H
#include <QObject>

#include "song.h"


class queueManager final : public QObject
{
    Q_OBJECT

public:
    static queueManager *getInstance();


private:
    static queueManager *instance;
    queueManager();

    QVector<song> queue;
};



#endif //QUEUEMANAGER_H
