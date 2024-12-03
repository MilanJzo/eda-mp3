//
// Created by Markus Heming on 03.12.24.
//

#include "libraryManager.h"
#include <QFileDialog>

QStringList libraryManager::openFileDialog()
{
    QStringList files = QFileDialog::getOpenFileNames(nullptr, "Select MP3 Files", "", "MP3 Files(*.mp3)");
    return files;
}
