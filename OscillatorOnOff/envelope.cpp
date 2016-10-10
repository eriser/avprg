#include <QDebug>
#include <math.h>
#include "envelope.h"

Envelope::Envelope()
    : gain(0)
{}
void Envelope::setSampleRate(float sampleRate){
    this->sampleRate = sampleRate;
}

void Envelope::on(){
    gain = 1;
}
void Envelope::off(){
    gain = 0;
}


float Envelope::process(float input){
    return gain * input;
}
