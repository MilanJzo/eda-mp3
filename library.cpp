//
// Created by fruit on 29.11.24.
//

#include "library.h"

library::library(QWidget *parent) : QWidget(parent), singletonPtr(this)
{
}

library *library::getInstance(QWidget *parent)
{
    if (singletonPtr == nullptr)
    {
        singletonPtr = new library(parent);
    }
    return singletonPtr;
}
