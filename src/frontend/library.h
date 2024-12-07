//
// Created by Markus Heming on 03.12.24.
//

#ifndef LIBRARY_H
#define LIBRARY_H

#include <QWidget>
#include <QStringList>

#include "../backend/libraryManager.h"


QT_BEGIN_NAMESPACE
namespace Ui { class library; }
QT_END_NAMESPACE

class library : public QWidget {
Q_OBJECT

public:
    explicit library(QWidget *parent = nullptr);
    ~library() override;


private slots:
    void on_addButton_clicked() const;

private:
    Ui::library *ui;
    libraryManager *manager;

    void renderSongs(QVector<song> songs);
};


#endif //LIBRARY_H
