//
// Created by fruit on 11.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_switcher.h" resolved

#include "switcher.h"

#include "editor.h"
#include "ui_switcher.h"

switcher* switcher::instance = nullptr;

switcher* switcher::getInstance() {
    if (instance == nullptr) { instance = new switcher(); }
    return instance;
}

switcher::switcher(QWidget *parent) :
    QWidget(parent), ui(new Ui::switcher) {
    ui->setupUi(this);

    lib = new library(this);
    ui->verticalLayout->addWidget(lib);
}

void switcher::onEditPlaylist(const playlist &p) {
    lib->close();
    edit = new editor(this, p);
    ui->verticalLayout->addWidget(edit);
}

void switcher::onBackButtonClicked() {
    delete edit;
    lib->show();
}

switcher::~switcher() {
    delete ui;
}
