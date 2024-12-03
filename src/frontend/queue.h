//
// Created by fruit on 03.12.24.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class queue; }
QT_END_NAMESPACE

class queue : public QWidget {
Q_OBJECT

public:
    explicit queue(QWidget *parent = nullptr);
    ~queue() override;

private:
    Ui::queue *ui;
};


#endif //QUEUE_H
