//
// Created by fruit on 02.12.24.
//

#ifndef CONTROLS_H
#define CONTROLS_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class controls; }
QT_END_NAMESPACE

class controls : public QWidget {
Q_OBJECT

public:
    explicit controls(QWidget *parent = nullptr);
    ~controls() override;

private:
    Ui::controls *ui;
};


#endif //CONTROLS_H
