//
// Created by fruit on 10.12.2024.
//

#ifndef ADDTOPLAYLIST_H
#define ADDTOPLAYLIST_H

#include <QWidget>

#include "../backend/playlist.h"


QT_BEGIN_NAMESPACE
namespace Ui { class addtoplaylist; }
QT_END_NAMESPACE

class addtoplaylist : public QWidget {
Q_OBJECT

public:
    explicit addtoplaylist(QWidget *parent = nullptr, QString name = "Missing Name", const song &s = song(QUrl(), QPixmap(":image/placeholder.png"), "Not Found", "Not Found", "Not Found"));
    ~addtoplaylist() override;

private slots:
    void onSelectClicked();

signals:
    void playlistSelected(playlist &p);

private:
    Ui::addtoplaylist *ui;
    const song &s;
};


#endif //ADDTOPLAYLIST_H
