#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    M_Player = new QMediaPlayer();

    ui->pushButton_Play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));


    audioOutput = new QAudioOutput();
    vol = static_cast<qfloat16>(ui->horizontalSlider_Volume_Control->value()/100.0);
    audioOutput->setVolume(vol);
    M_Player->setAudioOutput(audioOutput);


    //Open File: add action to button manually -yikes
    actionOpen_File = new QAction(tr("Open File"),this);
    connect(actionOpen_File,&QAction::triggered,this, &MainWindow::on_actionOpen_File_triggered);
    connect(ui->pushButton_Open_File, &QPushButton::clicked, actionOpen_File, &QAction::trigger);


    connect(ui->horizontalSlider_Volume_Control, &QSlider::valueChanged, this, &MainWindow::on_horizontalSlider_valueChanged);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_File_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this,tr("Select Audio File"),"",tr("MP3 Files (*.MP3)"));
    M_Player->setSource(QUrl::fromLocalFile(FileName));
    QFileInfo File(FileName);
    ui->label_Value_File_Name->setText(File.fileName());
}

void MainWindow::on_pushButton_Play_clicked()
{
    qDebug() << "is playing";
    M_Player->play();
}


void MainWindow::on_pushButton_Pause_clicked()
{
    M_Player->pause();
}





void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    vol = static_cast<qfloat16>(ui->horizontalSlider_Volume_Control->value()/100.0);
    qDebug() << "Setting volume to:" << vol;
    audioOutput->setVolume(vol);
    qDebug() << "Current volume:" << audioOutput->volume();
    M_Player->setAudioOutput(audioOutput);
}

