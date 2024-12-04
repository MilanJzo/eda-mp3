//
// Created by Markus Heming on 03.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_library.h" resolved

#include "library.h"
#include "ui_library.h"
#include <QDebug>
#include "../backend/libraryManager.h"
#include <QAction>


library::library(QWidget *parent) :
    QWidget(parent), ui(new Ui::library) {
    ui->setupUi(this);

    actionTrigger = new QAction(this);
    connect(actionTrigger, &QAction::triggered, this, &library::on_actionTrigger_triggered);
    connect(ui->addButton, &QPushButton::clicked, actionTrigger, &QAction::trigger);
}

library::~library() {
    delete ui;
}


void library::on_actionTrigger_triggered()
{
    qDebug() << "addButton clicked";
    libraryManager::addDirectory();
}

