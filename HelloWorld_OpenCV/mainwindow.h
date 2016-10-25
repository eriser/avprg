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

private:
    void createImage(cv::Mat& mat);
    void showImage(const cv::Mat& mat);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
