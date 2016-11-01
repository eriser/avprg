#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QMainWindow>
#include <QImage>
#include "videoengine.h"
#include "brightnessprocessor.h"
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
    void on_brightnessSlider_valueChanged(int value);
    void on_actionDatei_triggered();
    void on_actionKamera_triggered();
    void on_actionPlay_triggered();
private:
    Ui::VideoPlayer *ui;
    VideoEngine *videoThread;
    BrightnessProcessor* brightnessProcessor;
};

#endif // VIDEOPLAYER_H
