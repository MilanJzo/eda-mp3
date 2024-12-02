#include "./src/frontend/window.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        if (const QString baseName = "eda-mp3_" + QLocale(locale).name(); translator.load(":/i18n/" + baseName)) {
            QApplication::installTranslator(&translator);
            break;
        }
    }
    window w;
    w.show();
    return QApplication::exec();
}
