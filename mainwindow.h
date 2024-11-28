#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtMultimedia>
#include <QFileDialog>
#include <QStyle>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_Play_Pause_clicked();

    void on_actionOpen_File_triggered();

    void on_verticalSlider_Volume_valueChanged(int value);

    void on_pushButton_Seek_Backward_clicked();

    void on_pushButton_Seek_Forward_clicked();

    void on_horizontalSlider_Duration_valueChanged(int value);

    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);

private:

    Ui::MainWindow *ui;
    QMediaPlayer *M_Player;
    QAudioOutput *audioOutput;
    qfloat16 vol;
    qfloat16 volScale;
    qint64 Mduration;
    bool isPlaying;

    void updateDuration(qint64 duration);

    //Open File: add action to button manually -yikes
    QAction *actionOpen_File;

};
#endif // MAINWINDOW_H
