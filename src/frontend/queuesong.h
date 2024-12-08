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

class queueSong final : public QWidget {
Q_OBJECT

public:
    explicit queueSong(QWidget *parent = nullptr, const song &s);

    ~queueSong() override;

private slots:
    void onRemoveFromQueueClicked() const;

private:
    Ui::queueSong *ui;
    const song thisSong;
};


#endif //QUEUESONG_H
