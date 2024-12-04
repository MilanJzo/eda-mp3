//
// Created by Markus Heming on 03.12.24.
//

#ifndef LIBRARY_H
#define LIBRARY_H

#include <QWidget>
#include <QStringList>


QT_BEGIN_NAMESPACE
namespace Ui { class library; }
QT_END_NAMESPACE

class library : public QWidget {
Q_OBJECT

public:
    explicit library(QWidget *parent = nullptr);
    ~library() override;

private slots:
    void on_addButton_clicked();

private:
    Ui::library *ui;
};


#endif //LIBRARY_H
