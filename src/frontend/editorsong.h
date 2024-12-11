//
// Created by fruit on 11.12.24.
//

#ifndef EDITORSONG_H
#define EDITORSONG_H

#include <QWidget>

#include "../backend/song.h"


QT_BEGIN_NAMESPACE
namespace Ui { class editorsong; }
QT_END_NAMESPACE

class editorsong : public QWidget {
Q_OBJECT

public:
    explicit editorsong(QWidget *parent = nullptr, const song &s = song(QUrl(), QPixmap(), "Unknown", "Unknown", "00:00"));
    ~editorsong() override;

private:
    Ui::editorsong *ui;
    song thisSong;
};


#endif //EDITORSONG_H
