//
// Created by fruit on 11.12.24.
//

#ifndef EDITORSONG_H
#define EDITORSONG_H

#include <QWidget>

#include "editor.h"
#include "../backend/song.h"


QT_BEGIN_NAMESPACE
namespace Ui { class editorsong; }
QT_END_NAMESPACE

class editorsong : public QWidget {
Q_OBJECT

public:
    explicit editorsong(editor *parent = nullptr, const song &s = song(QUrl(), QPixmap(), "Unknown", "Unknown", "00:00"), int index = 0);
    ~editorsong() override;

public slots:
    void onDeleteFromPlaylistClicked();

signals:
    void deleteSongFromPlaylist(int songIndex);

private:
    Ui::editorsong *ui;
    song thisSong;
    int index;
};


#endif //EDITORSONG_H
