#include "./src/frontend/mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleSheet(":styles/style.qss");
    styleSheet.open(QFile::ReadOnly);
    a.setStyleSheet(styleSheet.readAll());

    MainWindow w;
    w.show();
    return QApplication::exec();
}
