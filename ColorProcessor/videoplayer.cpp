#include <QFileDialog>
#include "videoplayer.h"
#include "ui_videoplayer.h"

VideoPlayer::VideoPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoPlayer)
    , videoThread(new VideoEngine)
    , colorProcessor(new ColorProcessor)
{
    ui->setupUi(this);
    videoThread->setProcessor(colorProcessor);
    connect(videoThread, &VideoEngine::sendInputImage, ui->inputFrame, &VideoWidget::setImage);
    connect(videoThread, &VideoEngine::sendProcessedImage, ui->processedFrame, &VideoWidget::setImage);
}

VideoPlayer::~VideoPlayer()
{
    delete videoThread;
    delete colorProcessor;
    delete ui;
}



void VideoPlayer::on_actionDatei_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"),QDir::homePath());

    if (!fileName.isEmpty()) {
        videoThread->openFile(fileName);
     }
}

void VideoPlayer::on_actionKamera_triggered()
{
    videoThread->openCamera();
}

void VideoPlayer::on_actionPlay_triggered()
{
  videoThread->start();
}

void VideoPlayer::on_thresholdSlider_valueChanged(int value)
{
    colorProcessor->setThreshold(value);
}
