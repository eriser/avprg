#ifndef BRIGHTNESSPROCESSOR_H
#define BRIGHTNESSPROCESSOR_H

#include "videoprocessor.h"

class BrightnessProcessor : public VideoProcessor
{
public:
    BrightnessProcessor();
    void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat&source);
    void setOffset(int offset);
private:
    int offset;
};

#endif // BRIGHTNESSPROCESSOR_H
