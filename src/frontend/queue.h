//
// Created by fruit on 03.12.24.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <QWidget>

#include "../backend/queueManager.h"


QT_BEGIN_NAMESPACE
namespace Ui { class queue; }
QT_END_NAMESPACE

class queue final : public QWidget {
Q_OBJECT

public:
    explicit queue(QWidget *parent = nullptr);
    ~queue() override;

private slots:
    void onQueueChanged();

private:
    Ui::queue *ui;

    void renderQueue();
};


#endif //QUEUE_H
