#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include "cvmattoqimage.h"

using namespace cv;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // create empty Mat-Object (=Image)
    Mat image(300, 400, CV_8UC3);


//    createImage(image);
    schachbrett(image);
    showImage(image);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::schachbrett(cv::Mat& mat){
    const Scalar black(0,0,0);
    const Scalar white(255,255,255);

    int width = mat.cols/10;
    int height = mat.rows/10;

    mat.setTo(white);
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
            if((x + y)%2 == 0){
                Point linksOben(x*width, y*height);
                Point rechtsUnten(x*width+width, y*height+height);
                rectangle(mat, linksOben, rechtsUnten, black, CV_FILLED);
            }
        }
    }
}

void MainWindow::createImage(Mat& image){
    // Bildbreite
    int width = image.cols;
    int height = image.rows;

    // set background color
    Scalar yellow = Scalar(0, 200, 200);
    image.setTo(yellow);

    // draw a red rectangle
    Scalar red = Scalar(0, 0, 255);
    rectangle(image, Point(100,100), Point(200,200), red, 3);

    // draw cyan colored text
    Scalar cyan = Scalar(255, 255, 0);
    putText(image, "Hello World", Point(50, 150), FONT_HERSHEY_SIMPLEX, 2, cyan, 2);

}


void MainWindow::showImage(const Mat &mat){
    // convert Mat object to QPixmap object
    QPixmap pixmap = cvMatToQPixmap(mat);

    // set QPixmap object for QLabel
    ui->imageLabel->setPixmap(pixmap);
}
