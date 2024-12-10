//
// Created by Markus on 10.12.2024.
//

#ifndef SONGTOPLAYLISTDIALOG_H
#define SONGTOPLAYLISTDIALOG_H

#include <qdialog.h>
#include <QWidget>

#include "../backend/playlist.h"
#include "../backend/song.h"


QT_BEGIN_NAMESPACE
namespace Ui { class songToPlaylistDialog; }
QT_END_NAMESPACE

class songToPlaylistDialog final : public QDialog {
Q_OBJECT

public:
    ~songToPlaylistDialog() override;
    static songToPlaylistDialog* getInstance();

public slots:
    void onAddToPlaylist(const song &s);
    void onPlaylistChanged();

private:
    Ui::songToPlaylistDialog *ui;

    song &s;

    static songToPlaylistDialog *instance;

    explicit songToPlaylistDialog(QWidget *parent = nullptr);
    void renderPlaylists();
};


#endif //SONGTOPLAYLISTDIALOG_H
