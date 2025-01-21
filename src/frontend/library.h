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
    void onSetStatusText(const QString& statusText) const;
    void onSearch(const QString &searchTerm);
    void onAddButtonClicked() const;
    void onDownloadButtonClicked();
    void onSearchInitiated();
    void onLibraryChanged();

signals:
    QString songDownloadRequest(const QString &url);

private:
    Ui::library *ui;

    QVector<song> searchResults;
    bool noResults = false;

    void renderSongs();
};


#endif //LIBRARY_H
