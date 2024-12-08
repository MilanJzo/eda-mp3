//
// Created by fruit on 02.12.24.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFileDialog>
#include <QStyle>

class player final : public QMediaPlayer
{
    Q_OBJECT
public:
    static player* getInstance();

    void toggleMute() const;

private:
    explicit player();
    static player* instance;

};

#endif //PLAYER_H
