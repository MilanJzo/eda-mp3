//
// Created by Markus Heming on 03.12.24.
//

#include "libraryManager.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <QDir>

#include "player.h"

libraryManager *libraryManager::instance = nullptr;

libraryManager::libraryManager() : library(QStringList()) {
    loadLibrary();
}

libraryManager* libraryManager::getInstance()
{
    if (instance == nullptr) { instance = new libraryManager(); }
    return instance;
}

void libraryManager::loadLibrary()
{
    QFile file("./libraryDirectories.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Failed to open libraryDirectories.txt";
        return;
    }

    QTextStream stream(&file);
    while (!stream.atEnd()) {
        library.append(getMP3FilesFromDirectory(stream.readLine()));
    }

    file.close();
    qDebug() << "Loaded library";
}

void libraryManager::addDirectory() {
    const QString dir = QFileDialog::getExistingDirectory(nullptr, "Select Directory", QDir::homePath());

    QFile file("./libraryDirectories.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Failed to open libraryDirectories.txt";
        return;
    }

    QTextStream stream(&file);
    while (!stream.atEnd()) {
        if (stream.readLine().compare(dir) == 0)
        {
            qWarning() << "Directory already in libraryDirectories.txt";
            return;
        }
    }

    stream << dir << "\n";
    file.close();

    library.append(getMP3FilesFromDirectory(dir));
    qDebug() << "Added directory to library";
}

QStringList libraryManager::getMP3FilesFromDirectory(const QString& pathToDir)
{
    const QDir dir(pathToDir);
    QStringList filters;
    filters << "*.mp3";
    return dir.entryList(filters, QDir::Files);
}