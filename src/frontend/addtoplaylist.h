//
// Created by fruit on 11.12.24.
//

#ifndef ADDTOPLAYLIST_H
#define ADDTOPLAYLIST_H

#include <QWidget>

#include "../backend/song.h"


QT_BEGIN_NAMESPACE
namespace Ui { class addtoplaylist; }
QT_END_NAMESPACE

class addtoplaylist : public QWidget {
Q_OBJECT

public:
    explicit addtoplaylist(QWidget *parent = nullptr, QString name = "Name Not Found", const song &s = song(QUrl(), QPixmap(), "Unknown", "Unknown", "00:00"));
    ~addtoplaylist() override;

private slots:
    void onAddClicked();

private:
    Ui::addtoplaylist *ui;
    song thisSong;
};


#endif //ADDTOPLAYLIST_H
