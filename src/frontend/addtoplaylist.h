//
// Created by fruit on 11.12.24.
//

#ifndef ADDTOPLAYLIST_H
#define ADDTOPLAYLIST_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class addtoplaylist; }
QT_END_NAMESPACE

class addtoplaylist : public QWidget {
Q_OBJECT

public:
    explicit addtoplaylist(QWidget *parent = nullptr, QString name = "Name Not Found");
    ~addtoplaylist() override;

private:
    Ui::addtoplaylist *ui;
};


#endif //ADDTOPLAYLIST_H
