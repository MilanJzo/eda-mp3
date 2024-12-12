//
// Created by fruit on 11.12.24.
//

#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>

#include "../backend/playlist.h"


QT_BEGIN_NAMESPACE
namespace Ui { class editor; }
QT_END_NAMESPACE

class editor : public QWidget {
Q_OBJECT

public:
    explicit editor(QWidget *parent = nullptr, const playlist &p = playlist("???"), int index = 0);
    ~editor() override;

private slots:
    void onDeleteClicked();

signals:
    void deletePlaylist(int index);

private:
    Ui::editor *ui;
    int index;
    playlist thisPlaylist;
};


#endif //EDITOR_H
