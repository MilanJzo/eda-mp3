//
// Created by fruit on 11.12.2024.
//

#ifndef PLAYLISTINLIST_H
#define PLAYLISTINLIST_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class playlistinlist; }
QT_END_NAMESPACE

class playlistinlist : public QWidget {
Q_OBJECT

public:
    explicit playlistinlist(QWidget *parent = nullptr, const QString &name = "??????");
    ~playlistinlist() override;

private:
    Ui::playlistinlist *ui;
};


#endif //PLAYLISTINLIST_H
