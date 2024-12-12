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
    QWidget(parent), ui(new Ui::switcher), currentPlaylist("") {
    ui->setupUi(this);

    lib = new library(this);
    ui->verticalLayout->addWidget(lib);
}

void switcher::onEditPlaylist(const playlist &p, int index) {
    if (currentPlaylist != p.getName())
    {
        if (currentPlaylist != "") { delete edit; } // Erster Kommentar ;), das hier war der Absturzgrund während der Präsetation, weil das if()-statement fehlte. Behoben am 11.12.24 um 16:43uhr.
        currentPlaylist = p.getName();
        lib->close();
        edit = new editor(this, p);
        ui->verticalLayout->addWidget(edit);
    }
}

void switcher::onBackButtonClicked() {
    delete edit;
    currentPlaylist = "";
    lib->show();
}

switcher::~switcher() {
    delete ui;
}
