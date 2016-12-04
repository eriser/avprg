#include <math.h>
#include "Oscillator.h"

const float pi = 3.1415926f;

Oscillator::Oscillator()
: sampleRate(0), index(0), frequency(0)
{}

Oscillator::~Oscillator(void)
{
}
void Oscillator::initialize(float sampleRate){
	this->sampleRate = sampleRate;
}
void Oscillator::setFrequency(float setFrequency){
	frequency = setFrequency;
}

float Oscillator::getValue(){
	float value = sin(2 * pi * index * frequency / sampleRate);
	index++;
	return value;
}
