//
// Created by Markus Heming on 11.12.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_addtoplaylistdialog.h" resolved

#include "addtoplaylistdialog.h"

#include "addtoplaylist.h"
#include "ui_addtoplaylistdialog.h"
#include "../backend/playlistManager.h"

//creates a dialog window to add a song to a playlist
addtoplaylistdialog::addtoplaylistdialog(QWidget *parent, const song &s) :
    QDialog(parent), ui(new Ui::addtoplaylistdialog)
{
    ui->setupUi(this);

    for (const auto& playlist : playlistManager::getInstance()->getPlaylists()) {
        const auto item = new QListWidgetItem(ui->listWidget);
        const auto playlistWidget = new addtoplaylist(this, playlist.getName(), s);

        item->setSizeHint(playlistWidget->sizeHint());

        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, playlistWidget);
    }
}

addtoplaylistdialog::~addtoplaylistdialog() {
    delete ui;
}
