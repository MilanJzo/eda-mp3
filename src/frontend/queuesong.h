//
// Created by fruit on 08.12.2024.
//

#ifndef QUEUESONG_H
#define QUEUESONG_H

#include <QWidget>

#include "../backend/song.h"


QT_BEGIN_NAMESPACE
namespace Ui { class queueSong; }
QT_END_NAMESPACE

class queueSong : public QWidget {
Q_OBJECT

public:
    explicit queueSong(QWidget *parent = nullptr, const song &s = song(QUrl(), QImage(), "Unknown", "Unknown"));
    ~queueSong() override;

private slots:
    void onRemoveFromQueueClicked();

signals:
    void removeFromQueue(const song &s) const;

private:
    Ui::queueSong *ui;
    song thisSong;
};


#endif //QUEUESONG_H
