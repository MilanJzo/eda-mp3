//
// Created by fruit on 03.12.24.
//

#ifndef CONTROLS_H
#define CONTROLS_H

#include <QMediaPlayer>
#include <QWidget>


class player;
QT_BEGIN_NAMESPACE
namespace Ui { class controls; }
QT_END_NAMESPACE

class controls final : public QWidget {
Q_OBJECT

public:
    explicit controls(QWidget *parent = nullptr);
    ~controls() override;

private slots:
    void onDurationChanged(qint64 duration) const;
    void onPlaybackStateChanged(QMediaPlayer::PlaybackState state) const;
    void onPositionChanged(qint64 progress) const;
    void onMetaDataChanged() const;

    void onMutedChanged(bool muted) const;
    void onLoopStateToggled();

    void onPlayPauseClicked() const;
    void onVolumeButtonClicked() const;

    void onVolumeSliderValueChanged(int value) const;
    void onProgressSliderReleased() const;
    void onProgressSliderValueChanged(int value) const;

private:
    Ui::controls *ui;
    player* Player;


    enum class LoopingState {
        None,
        Loop,
        LoopOne
    };
    LoopingState loopState = LoopingState::None;
};


#endif //CONTROLS_H
