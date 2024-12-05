//
// Created by Markus Heming on 03.12.24.
//

#include "libraryManager.h"
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QFile>

void libraryManager::addDirectory() {
    qDebug() << "addDirectory called";

    QFile file("./libraryDirectories.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        qWarning() << "Could not open file for writing";
        return;
    }

    QTextStream writeStream(&file);
    writeStream << "something" << Qt::endl;
    file.close();

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for reading";
        return;
    }

    QTextStream readStream(&file);
    while (!readStream.atEnd()) {
        QString line = readStream.readLine();
        qDebug() << line;
    }

    file.close();
}

QStringList libraryManager::getMP3Files(const QString& directory)
{
    const QDir dir(directory);
    QStringList filters;
    filters << "*.mp3";
    return dir.entryList(filters, QDir::Files);
}

