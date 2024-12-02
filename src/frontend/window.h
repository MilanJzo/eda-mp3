//
// Created by fruit on 02.12.24.
//

#ifndef WINDOW_H
#define WINDOW_H

#include <QMediaPlayer>
#include <QMainWindow>

#include "../backend/player.h"


QT_BEGIN_NAMESPACE
namespace Ui { class window; }
QT_END_NAMESPACE

class window final : public QMainWindow {
Q_OBJECT

public:
    explicit window(QWidget *parent = nullptr);
    ~window() override;

private:
    Ui::window *ui;
};


#endif //WINDOW_H
