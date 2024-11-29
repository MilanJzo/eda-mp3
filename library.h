//
// Created by fruit on 29.11.24.
//

#ifndef LIBRARY_H
#define LIBRARY_H
#include <QWidget>


class library final : QWidget{
public :
    explicit library(QWidget* parent);

    void addFolders();
    void refresh();
    library* getInstance(QWidget* parent);
private:
    library* singletonPtr;
};



#endif //LIBRARY_H
