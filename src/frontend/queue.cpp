//
// Created by fruit on 03.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_queue.h" resolved

#include "queue.h"

#include "queuesong.h"
#include "ui_queue.h"
#include "../backend/queueManager.h"


queue::queue(QWidget *parent) :
    QWidget(parent), ui(new Ui::queue) {
    ui->setupUi(this);

    connect(queueManager::getInstance(), queueManager::queueChanged, this, &queue::onQueueChanged);
    connect(ui->clearButton, QPushButton::clicked, queueManager::getInstance(), &queueManager::onClearQueue);
}

void queue::onQueueChanged() {
    renderSongs();
}

void queue::renderSongs() {
    ui->listWidget->clear();

    auto queue = queueManager::getInstance()->getQueue();
    for (int i = 0; i < queue.size(); i++) {
        const auto item = new QListWidgetItem(ui->listWidget);
        const auto songWidget = new queueSong(this, queue.at(i), i);

        if (i == 0) {
            songWidget->setStyleSheet("#songContent { background-color: #1A574B; }");
        }

        item->setSizeHint(songWidget->sizeHint());

        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, songWidget);
    }
    qDebug() << "Rendered songs";
}

queue::~queue() {
    delete ui;
}
