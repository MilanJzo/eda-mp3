//
// Created by fruit on 02.12.24.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFileDialog>
#include <QStyle>

class player {
public:
    static player* getInstance();

signals:
    void togglePlay();
    void setVolume(int volume);
    void skipToNextSong();
    void skipToLastSong();
    void toggleShuffle();
    void toggleMute();
    void setPosition(int position) const;
    void setSong(QUrl fileUrl) const;
    void updatePosition() const;

    void positionChanged(qint64 progress);
    void durationChanged(qint64 duration) const;

    void setDuration(int duration);

    [[nodiscard]] bool getIsPlaying() const { return isPlaying; }
    [[nodiscard]] bool getIsMuted() const {return isMuted; }
    [[nodiscard]] qint64 getDuration() const { return M_Player->duration(); }

private:
    player();
    QMediaPlayer* M_Player;
    static player* instance;
    QAudioOutput* audioOutput;

    qfloat16 vol;
    qfloat16 volScale;

    bool isPlaying;
    bool isMuted;

};

#endif //PLAYER_H
