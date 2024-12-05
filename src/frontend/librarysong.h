//
// Created by fruit on 05.12.24.
//

#ifndef LIBRARYSONG_H
#define LIBRARYSONG_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class librarysong; }
QT_END_NAMESPACE

class librarysong : public QWidget {
Q_OBJECT

public:
    explicit librarysong(QWidget *parent = nullptr, const QString &title = "", const QString &artist = "");
    ~librarysong() override;

private:
    Ui::librarysong *ui;
};


#endif //LIBRARYSONG_H
