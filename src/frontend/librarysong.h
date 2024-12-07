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
    explicit librarysong(QWidget *parent = nullptr, const song &s = song(QUrl(), "Unknown", "Unknown"));
    ~librarysong() override;

void on_playDirectly_clicked();

void onPlayDirectlyClicked();

private:
    Ui::librarysong *ui;
    song thisSong;
};


#endif //LIBRARYSONG_H
