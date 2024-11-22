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
    ui->pushButton_Seek_Forward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButton_Seek_Backward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));


    audioOutput = new QAudioOutput();
    vol = static_cast<qfloat16>(ui->verticalSlider_Volume->value()/1000.0);
    audioOutput->setVolume(vol);
    M_Player->setAudioOutput(audioOutput);


    //Open File: add action to button manually -yikes
    actionOpen_File = new QAction(tr("Open File"),this);
    connect(actionOpen_File,&QAction::triggered,this, &MainWindow::on_actionOpen_File_triggered);
    connect(ui->pushButton_Open_File, &QPushButton::clicked, actionOpen_File, &QAction::trigger);


    connect(ui->verticalSlider_Volume, &QSlider::valueChanged, this, &MainWindow::on_verticalSlider_Volume_valueChanged);

    connect(M_Player, &QMediaPlayer:: durationChanged, this, &MainWindow::durationChanged);
    connect(M_Player, &QMediaPlayer:: positionChanged, this, &MainWindow::positionChanged);

    ui->horizontalSlider_Duration->setRange(0, M_Player->duration() / 1000);

    connect(ui->horizontalSlider_Duration, &QSlider::sliderMoved, this, &MainWindow::on_horizontalSlider_Duration_sliderMoved);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDuration(qint64 duration)
{
    // QString timestr;
    if (duration || Mduration) {
        QTime currentTime((duration/3600) % 60,(duration/60) % 60,duration % 60,(duration * 1000) % 1000);
        QTime totalTime((Mduration/3600) % 60,(Mduration/60) % 60,Mduration % 60,(Mduration * 1000) % 1000);
        QString format = "mm:ss";
        if (Mduration > 3600)
            format = "hh:mm:ss";
        ui->label_Current_Time->setText(currentTime.toString(format));
        ui->label_Total_Time->setText(totalTime.toString(format));
    }
}

void MainWindow::durationChanged(qint64 duration)
{
    Mduration = duration / 1000;
    ui->horizontalSlider_Duration->setMaximum(Mduration);
}

void MainWindow::positionChanged(qint64 progress)
{
    if(!ui->horizontalSlider_Duration->isSliderDown()) {
        ui->horizontalSlider_Duration->setValue(progress / 1000);
    }

    updateDuration(progress / 1000);
}

void MainWindow::on_horizontalSlider_Duration_sliderMoved(int position)
{
    M_Player->setPosition(position * 1000);
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
    // qDebug() << "is playing";
    M_Player->play();
}

void MainWindow::on_pushButton_Pause_clicked()
{
    M_Player->pause();
}

void MainWindow::on_verticalSlider_Volume_valueChanged(int value)
{
    vol = static_cast<qfloat16>(ui->verticalSlider_Volume->value()/1000.0);
    // qDebug() << "Setting volume to:" << vol;
    audioOutput->setVolume(vol);
    // qDebug() << "Current volume:" << audioOutput->volume();
    M_Player->setAudioOutput(audioOutput);
}

void MainWindow::on_pushButton_Seek_Forward_clicked()
{
    ui->horizontalSlider_Duration->setValue(ui->horizontalSlider_Duration->value() + 30);
    M_Player->setPosition(ui->horizontalSlider_Duration->value()*1000);
}

void MainWindow::on_pushButton_Seek_Backward_clicked()
{
    ui->horizontalSlider_Duration->setValue(ui->horizontalSlider_Duration->value() - 30);
    M_Player->setPosition(ui->horizontalSlider_Duration->value()*1000);
}

void MainWindow::on_horizontalSlider_Duration_valueChanged(int value)
{
    // M_Player->setPosition(value * 1000);
}


