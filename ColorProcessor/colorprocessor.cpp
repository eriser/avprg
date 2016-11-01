#include "colorprocessor.h"

using namespace cv;

const int REF_R = 102;
const int REF_G = 30;
const int REF_B = 36;

ColorProcessor::ColorProcessor()
    :threshold(10)
{
}
void ColorProcessor::setThreshold(int threshold){
    this->threshold = threshold;
}

Mat ColorProcessor::process(const Mat &input){
    Mat output(input.rows, input.cols, input.type());

    int numWhitePixels = 0;
    int sumX = 0;
    int sumY = 0;

    for(int x = 0; x < input.cols; x++){
        for(int y = 0; y < input.rows; y++){
            Vec3b inputPixel = input.at<Vec3b>(y,x);
            int r = inputPixel[2];
            int g = inputPixel[1];
            int b = inputPixel[0];

            float distance = sqrt(pow((r - REF_R),2) + pow((g-REF_G),2)
                                  + pow((b-REF_B),2));

            if (distance < threshold){
                output.at<Vec3b>(y,x) = Vec3b(255,255,255);
                sumX += x;
                sumY += y;
                numWhitePixels ++;
            }
            else{
                output.at<Vec3b>(y,x) = Vec3b(0,0,0);
            }
        }
    }
    if(numWhitePixels > 0){
        int centerX = sumX / numWhitePixels;
        int centerY = sumY / numWhitePixels;
        line(output, Point(centerX, centerY - 5), Point(centerX, centerY + 5),
             Scalar(0, 255, 0), 2);
        line(output, Point(centerX-5, centerY), Point(centerX+5, centerY),
             Scalar(0, 255, 0), 2);
    }
    return output;
}
