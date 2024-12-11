//
// Created by fruit on 11.12.24.
//

#ifndef EDITORSONG_H
#define EDITORSONG_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class editorsong; }
QT_END_NAMESPACE

class editorsong : public QWidget {
Q_OBJECT

public:
    explicit editorsong(QWidget *parent = nullptr);
    ~editorsong() override;

private:
    Ui::editorsong *ui;
};


#endif //EDITORSONG_H
