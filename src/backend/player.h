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
    player();
    static player* getInstance();

signals:
    void togglePlay();
    void setVolume(int value);
    void skipToNextSong();
    void skipToLastSong();
    void toggleShuffle();
    void toggleMute();
    void setPosition(int value) const;

    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);

    [[nodiscard]] bool getIsPlaying() const { return isPlaying; }
    [[nodiscard]] bool getIsMuted() const {return isMuted; }

private:
    QMediaPlayer* M_Player;
    static player* instance;
    QAudioOutput* audioOutput;
    qfloat16 vol;
    qfloat16 volScale;


    bool isPlaying;
    bool isMuted;

};

#endif //PLAYER_H
