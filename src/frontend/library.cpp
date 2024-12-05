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
}

library::~library() {
    delete ui;
}

void library::on_addButton_clicked()
{
    qDebug() << "addButton clicked";
    libraryManager::addDirectory();
}

