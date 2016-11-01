#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_ffnen_triggered();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    cv::Mat sourceImage;
    cv::Mat destinationImage;
    int threshold;
    void process();

};

#endif // MAINWINDOW_H
