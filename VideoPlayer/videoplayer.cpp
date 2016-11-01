#include <QFileDialog>
#include "videoplayer.h"
#include "ui_videoplayer.h"

VideoPlayer::VideoPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VideoPlayer)
    , videoThread(new VideoEngine)
{
    ui->setupUi(this);
    connect(videoThread, &VideoEngine::sendInputImage, ui->inputFrame, &VideoWidget::setImage);
}

VideoPlayer::~VideoPlayer()
{
    delete videoThread;
    delete ui;
}

void VideoPlayer::on_actionVideodatei_ffnen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"),QDir::homePath());

    if (!fileName.isEmpty()) {
        videoThread->openFile(fileName);
     }
}

void VideoPlayer::on_actionKamera_ffnen_triggered()
{
    videoThread->openCamera();
}

void VideoPlayer::on_actionPlay_triggered()
{
    videoThread->start();
}
