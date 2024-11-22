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
    // vol = ui->horizontalSlider_VC->value() / 100.0;
    // audioOutput = setVolume(vol);
    // M_Player->setAudioOuput(audioOutput);


    //Open File: manuelle Action Zuweisung zum Button
    actionOpen_File = new QAction(tr("Open File"),this);

    connect(actionOpen_File,&QAction::triggered,this, &MainWindow::on_actionOpen_File_triggered);
    connect(ui->pushButton_Open_File, &QPushButton::clicked, actionOpen_File, &QAction::trigger);

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

}


void MainWindow::on_pushButton_Pause_clicked()
{

}





void MainWindow::on_horizontalSlider_valueChanged(int value)
{

}

