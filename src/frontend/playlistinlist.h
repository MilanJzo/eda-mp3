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
    explicit playlistinlist(QWidget *parent = nullptr, const playlist &p = playlist("???"));
    ~playlistinlist() override;

private slots:
    void onPlayDirectlyClicked();

signals:
    void playPlaylistDirectly(const playlist &p);

private:
    Ui::playlistinlist *ui;
    playlist thisPlaylist;
};


#endif //PLAYLISTINLIST_H
