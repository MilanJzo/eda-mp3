//
// Created by fruit on 03.12.24.
//

#ifndef CONTROLS_H
#define CONTROLS_H

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
    void on_playPause_clicked() const;

    void on_skipBackwards_clicked();

    void on_skipForwards_clicked();

    void on_shuffle_clicked();

    void on_progress_valueChanged(int value) const;

    void setProgressRange(int value) const;

    void updateTimeLabels(int progress) const;

    void on_volumeButton_clicked() const;

    void on_volumeSlider_valueChanged(int value);

    void on_progress_sliderReleased() const;
private:
    Ui::controls *ui;
    player* Player;
};


#endif //CONTROLS_H
