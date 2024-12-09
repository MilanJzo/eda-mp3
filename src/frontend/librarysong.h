//
// Created by fruit on 05.12.24.
//

#ifndef LIBRARYSONG_H
#define LIBRARYSONG_H

#include <QWidget>

#include "../backend/song.h"


QT_BEGIN_NAMESPACE
namespace Ui { class librarysong; }
QT_END_NAMESPACE

class librarysong : public QWidget {
Q_OBJECT

public:
    explicit librarysong(QWidget *parent = nullptr, const song &s = song(QUrl(), QPixmap(), "Unknown", "Unknown", "00:00"));
    ~librarysong() override;

private slots:
    void onPlayDirectlyClicked();
    void onAddToQueueClicked();

signals:
    void playDirectly(const song &s) const;
    void addToQueue(const song &s) const;

private:
    Ui::librarysong *ui;
    song thisSong;
};


#endif //LIBRARYSONG_H
