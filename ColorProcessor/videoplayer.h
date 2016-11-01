#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QMainWindow>
#include <QImage>
#include "videoengine.h"
#include "colorprocessor.h"
namespace Ui {
class VideoPlayer;
}

class VideoPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoPlayer(QWidget *parent = 0);
    ~VideoPlayer();

private slots:
    void on_actionDatei_triggered();
    void on_actionKamera_triggered();
    void on_actionPlay_triggered();
    void on_thresholdSlider_valueChanged(int value);

private:
    Ui::VideoPlayer *ui;
    VideoEngine *videoThread;
    ColorProcessor* colorProcessor;
};

#endif // VIDEOPLAYER_H
