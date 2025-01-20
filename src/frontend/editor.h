//
// Created by fruit on 11.12.24.
//

#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>

#include "../backend/playlist.h"


QT_BEGIN_NAMESPACE
namespace Ui { class editor; }
QT_END_NAMESPACE

class editor final : public QWidget {
Q_OBJECT

public:
    explicit editor(QWidget *parent = nullptr, int playlistIndex = 0);
    ~editor() override;

public slots:
    void onDeleteSongFromPlaylistClicked(int songIndex);

private slots:
    void onDeleteClicked();
    void onPlaylistsChanged();

signals:
    void deletePlaylist(int index);
    void deleteSongFromPlaylist(int playlistIndex, int songIndex);

private:
    Ui::editor *ui;
    int playlistIndex;
    bool isPlaylistDeleted = false;

    void renderSongs();
};


#endif //EDITOR_H
