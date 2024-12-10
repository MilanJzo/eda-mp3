//
// Created by fruit on 10.12.2024.
//

#ifndef CREATEPLAYLISTDIALOG_H
#define CREATEPLAYLISTDIALOG_H

#include <qdialog.h>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class createplaylistdialog; }
QT_END_NAMESPACE

class createplaylistdialog : public QDialog {
Q_OBJECT

public:
    explicit createplaylistdialog(QWidget *parent = nullptr);
    ~createplaylistdialog() override;

private slots:
    void onCreateClicked();
    void onChooseCoverClicked();

private:
    Ui::createplaylistdialog *ui;
};

#endif //CREATEPLAYLISTDIALOG_H