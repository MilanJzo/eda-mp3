//
// Created by fruit on 11.12.2024.
//

#ifndef PLAYLISTINLIST_H
#define PLAYLISTINLIST_H

#include <QWidget>

#include "../backend/playlist.h"


QT_BEGIN_NAMESPACE
namespace Ui { class playlistinlist; }
QT_END_NAMESPACE

class playlistinlist : public QWidget {
Q_OBJECT

public:
    explicit playlistinlist(QWidget *parent = nullptr, const playlist &p = playlist("???"), int index = 0);
    ~playlistinlist() override;

private slots:
    void onPlayDirectlyClicked();
    void onQueuePlaylistClicked();
    void onEditPlaylistClicked();

signals:
    void playPlaylistDirectly(const playlist &p);
    void queuePlaylist(const playlist &p);
    void editPlaylist(int index);

private:
    Ui::playlistinlist *ui;
    playlist thisPlaylist;
    int index;
};


#endif //PLAYLISTINLIST_H
