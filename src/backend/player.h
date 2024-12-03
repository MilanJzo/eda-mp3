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

    void togglePlay();
    void setVolume(int volume) const;
    void skipToNextSong();
    void skipToLastSong();
    void setPosition(int value);

    [[nodiscard]] bool getPlaying() const { return isPlaying; }

private:
    QMediaPlayer* M_Player;
    static player* instance;

    QAudioOutput* audioOutput;

    bool isPlaying;

};

#endif //PLAYER_H
