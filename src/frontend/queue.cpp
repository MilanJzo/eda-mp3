//
// Created by fruit on 03.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_queue.h" resolved

#include "queue.h"

#include "queuesong.h"
#include "ui_queue.h"


queue::queue(QWidget *parent) :
    QWidget(parent), ui(new Ui::queue) {
    ui->setupUi(this);

    renderQueue();
    connect(queueManager::getInstance(), queueManager::queueChanged, this, &queue::onQueueChanged);
    connect(ui->clearButton, QPushButton::clicked, queueManager::getInstance(), &queueManager::onClearQueueClicked);
}

// TODO make queueSong and replace librarysong
void queue::renderQueue() {
    ui->listWidget->clear();

    auto queue = queueManager::getInstance()->getQueue();

    for (const song& song: queue) {
        const auto item = new QListWidgetItem(ui->listWidget);
        const auto songWidget = new queueSong(this, song);

        item->setSizeHint(songWidget->sizeHint());

        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, songWidget);
    }
    qDebug() << "Rendered Queue";
}

void queue::onQueueChanged() {
    renderQueue();
}

queue::~queue() {
    delete ui;
}
