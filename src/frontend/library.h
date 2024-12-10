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

class library final : public QWidget {
Q_OBJECT

public:
    explicit library(QWidget *parent = nullptr);
    ~library() override;

private slots:
    void onAddButtonClicked() const;
    void onLibraryChanged();

private:
    Ui::library *ui;

    void renderSongs();
};


#endif //LIBRARY_H
