#ifndef __DELAYPROCESSOR_H
#define __DELAYPROCESSOR_H
#include "RingBuffer.h"

const float DELAY_MAX_SEC = 1;
const float DELAY_DEFAULT_SEC = 0.5;
const float AMOUNT_DEFAULT_PERCENT = 50;
const float FEEDBACK_DEFAULT_PERCENT = 50;


class DelayProcessor{
public:
	DelayProcessor();
	void initialize(float sampleRate);
	float processOneSample(float input);
	void process(float* input, float* output, int numberOfSamples);
	void setAmount(float amount);
	void setFeedback(float feedback);
	void setDelay(float seconds);
private:
	RingBuffer buffer;
	float sampleRate;
	float delaySec;
	int delay;
	float amount;
	float feedback;
};
#endif