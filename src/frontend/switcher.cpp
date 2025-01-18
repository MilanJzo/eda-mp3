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

//exchanges the library window with the editor window when the edit button is clicked in the playlist window
void switcher::onEditPlaylist(const playlist &p, const int index) {
    if (currentPlaylist != p.getName())
    {
        if (currentPlaylist != "") { delete edit; }
        currentPlaylist = p.getName();
        lib->close();
        edit = new editor(this, p, index);
        ui->verticalLayout->addWidget(edit);
    }
}

//switches back to the library window when the back button is clicked in the editor window
void switcher::onBackButtonClicked() {
    delete edit;
    currentPlaylist = "";
    lib->show();
}

switcher::~switcher() {
    delete ui;
}
