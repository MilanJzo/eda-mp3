//
// Created by Markus Heming on 03.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_library.h" resolved

#include "library.h"
#include "ui_library.h"
#include <QDebug>


library::library(QWidget *parent) :
    QWidget(parent), ui(new Ui::library) {
    ui->setupUi(this);
}

library::~library() {
    delete ui;
}

//nur zum Testen
void library::displayFiles(const QStringList& files)
{
    for (const QString &file : files)
    {
        qDebug() << file;
    }
}

