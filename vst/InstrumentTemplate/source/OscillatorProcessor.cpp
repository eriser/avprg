#include "OscillatorProcessor.h"
#include <math.h>
OscillatorProcessor::OscillatorProcessor()
: isNoteOn(false), pitch(0), velocity(0), sampleRate(0), gain(1)
{
}

void OscillatorProcessor::initialize(float sampleRate){
	this->sampleRate = sampleRate;
	oscillator.initialize(sampleRate);
}
void OscillatorProcessor::setGain(float gain){
	this->gain = gain;
}
void OscillatorProcessor::noteOn(int pitch, int velocity){
	this->pitch = pitch;
	this->velocity = velocity;
	this->isNoteOn = true;

	float frequency = 440.0 * pow(2.0, (pitch - 69.0)/12.0);
	oscillator.setFrequency(frequency);
}
void OscillatorProcessor::noteOff(){
	this->isNoteOn = false;
}

float OscillatorProcessor::processOneSample(){
	if (isNoteOn == true){
		return oscillator.getValue() * gain;
	}
	return 0;
}
void OscillatorProcessor::process(float*output, int numberOfSamples){
	for(int i = 0; i < numberOfSamples; i++){
		output[i] = processOneSample();
	}
}