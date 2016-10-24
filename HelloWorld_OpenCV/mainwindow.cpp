#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    testImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testImage(){
    Scalar yellow = Scalar(0, 200, 200);

    Mat image(300, 400, CV_8UC3, yellow);

    Scalar red = Scalar(0, 0, 255);
    rectangle(image, Point(100,100), Point(200,200), red, 3);

    Scalar cyan = Scalar(255, 255, 0);
    putText(image, "Hello World", Point(50, 150), FONT_HERSHEY_SIMPLEX, 2, cyan, 2);

    showMat(image);
}


void MainWindow::showMat(const Mat &mat){
    // convert Mat object to QImage object
    QImage image( mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888 );
    image = image.rgbSwapped();

    // convert QImage object to QPixmap object
    QPixmap pixmap = QPixmap::fromImage(image);

    // set QPixmap object for QLabel
    ui->imageLabel->setPixmap(pixmap);
}
