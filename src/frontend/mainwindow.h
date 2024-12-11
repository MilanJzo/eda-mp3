#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "library.h"
#include "../backend/playlist.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow final : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
