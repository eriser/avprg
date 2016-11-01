#include "brightnessprocessor.h"

using namespace cv;

BrightnessProcessor::BrightnessProcessor()
    :offset(0)
{
}
void BrightnessProcessor::setOffset(int offset){
    this->offset = offset;
}
Mat BrightnessProcessor::process(const Mat &input){
    Mat output(input.rows, input.cols, input.type());
    for(int x = 0; x < input.cols; x++){
        for(int y = 0; y < input.rows; y++){
            Vec3b inputPixel = input.at<Vec3b>(y,x);
            int r = inputPixel[2] + offset;
            int g = inputPixel[1] + offset;
            int b = inputPixel[0] + offset;
            Vec3b outputPixel (b, g, r);//= inputPixel + offset;//brightnessOffset;
            output.at<Vec3b>(y,x) = outputPixel;
        }
    }
    return output;
}
