#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include "cvmattoqimage.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    threshold(127)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_ffnen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                  tr("Images (*.png *xpm *jpg"));
    sourceImage = imread(filename.toStdString());
    destinationImage.create(sourceImage.rows, sourceImage.cols, CV_8UC3);
 //   sourceImage.copyTo(destinationImage);

    process();

    ui->imageLabel->setPixmap(cvMatToQPixmap(sourceImage));
    ui->processedImageLabel->setPixmap(cvMatToQPixmap(destinationImage));
}

void MainWindow::process(){
    for(int x = 0; x < sourceImage.cols; x++){
        for(int y = 0; y < sourceImage.rows; y++){
            // read source pixel at position x,y
            Vec3b sourcePixel = sourceImage.at<Vec3b>(y,x);
            int b = sourcePixel[0];
            int g = sourcePixel[1];
            int r = sourcePixel[2] - 80;

            // process the pixel
            int gray = (r + g + b)/3;

            // convert to black/white
            if (gray > threshold){
                gray = 255;
            }
            else {
                gray = 0;
            }

            // write destination pixel at position x,y
            Vec3b destinationPixel(gray, gray, gray);
            destinationImage.at<Vec3b>(y, x) = destinationPixel;
        }
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    threshold = value;
    process();
    ui->processedImageLabel->setPixmap(cvMatToQPixmap(destinationImage));

}
