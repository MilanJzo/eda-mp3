//
// Created by Markus Heming on 11.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_addtoplaylistdialog.h" resolved

#include "addtoplaylistdialog.h"
#include "ui_addtoplaylistdialog.h"


addtoplaylistdialog::addtoplaylistdialog(QWidget *parent) :
    QWidget(parent), ui(new Ui::addtoplaylistdialog) {
    ui->setupUi(this);
}

addtoplaylistdialog::~addtoplaylistdialog() {
    delete ui;
}
