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
    w.setWindowIcon(QIcon(":/icon/logo.svg"));
    w.setWindowTitle("EDA MP3 - We died developing this.");
    w.setWindowOpacity(0.8);
    w.show();
    return QApplication::exec();
}
