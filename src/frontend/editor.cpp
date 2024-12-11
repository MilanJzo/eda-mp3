//
// Created by fruit on 11.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_editor.h" resolved

#include "editor.h"
#include "ui_editor.h"


editor::editor(QWidget *parent) :
    QWidget(parent), ui(new Ui::editor) {
    ui->setupUi(this);
}

editor::~editor() {
    delete ui;
}
