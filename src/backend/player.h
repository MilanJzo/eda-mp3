//
// Created by fruit on 02.12.24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <QMediaPlayer>


class player {
public:
    player();
    static player* getInstance();

    void togglePlay();
    [[nodiscard]] bool getPlaying() const { return isPlaying; }

private:
    QMediaPlayer* M_PLayer;
    static player* instance;

    bool isPlaying;

};

#endif //PLAYER_H
