#ifndef FLANGER_PROCESSOR_H
#define FLANGER_PROCESSOR_H

#include "Lfo.h"
#include "RingBuffer.h"

const float DELAY_MAX_SEC = 10.0 / 1000.0;	// max 10 ms Delay
const float FREQUENCY_MAX_HZ = 1;
const float FREQUENCY_DEFAULT_HZ = 0.05;
const float DELAY_DEFAULT_SEC = 1/1000;
const float DEPTH_DEFAULT_PERCENT = 90;
const float PHASE_DEFAULT_DEGREE = 90;
const float PI = 3.1415926;


class FlangerProcessor{
public:
	FlangerProcessor();
	void initialize(float sampleRate);
	float processOneSample(float);
	void process(float* input, float*output, int numberOfSamples);
	void setFrequency(float frequency);
	void setPhase(float phase);
	void setDepth(float depth);
	void setDelay(float delay);
private:
	float sampleRate;
	Lfo lfo;
	RingBuffer buffer;
	float depth;
	float delay;
	float phase;
};
#endif