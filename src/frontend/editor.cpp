//
// Created by fruit on 11.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_editor.h" resolved

#include "editor.h"

#include "editorsong.h"
#include "switcher.h"
#include "ui_editor.h"


editor::editor(QWidget *parent, const playlist &p) :
    QWidget(parent), ui(new Ui::editor) {
    ui->setupUi(this);

    ui->editorTitle->setText(p.getName());

    connect(ui->backButton, &QPushButton::clicked, switcher::getInstance(), &switcher::onBackButtonClicked);

    for (const song &s : p)
    {
        const auto item = new QListWidgetItem(ui->songList);
        const auto songWidget = new editorsong(this, s);

        item->setSizeHint(songWidget->sizeHint());

        ui->songList->addItem(item);
        ui->songList->setItemWidget(item, songWidget);
    }
}

editor::~editor() {
    delete ui;
}
