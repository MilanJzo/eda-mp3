//
// Created by fruit on 03.12.24.
//

#ifndef CONTROLS_H
#define CONTROLS_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class controls; }
QT_END_NAMESPACE

class controls : public QWidget {
Q_OBJECT

public:
    explicit controls(QWidget *parent = nullptr);
    ~controls() override;

private slots:
    void on_playPause_clicked();

    void on_skipBackwards_clicked();

    void on_skipForwards_clicked();

    void on_shuffle_clicked();

    void on_progress_valueChanged(int value);

    void on_volume_clicked();

private:
    Ui::controls *ui;
};


#endif //CONTROLS_H
