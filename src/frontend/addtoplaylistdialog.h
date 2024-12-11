//
// Created by Markus Heming on 11.12.24.
//

#ifndef ADDTOPLAYLISTDIALOG_H
#define ADDTOPLAYLISTDIALOG_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class addtoplaylistdialog; }
QT_END_NAMESPACE

class addtoplaylistdialog final : public QWidget {
Q_OBJECT

public:
    explicit addtoplaylistdialog(QWidget *parent = nullptr);
    ~addtoplaylistdialog() override;

private:
    Ui::addtoplaylistdialog *ui;
};


#endif //ADDTOPLAYLISTDIALOG_H
