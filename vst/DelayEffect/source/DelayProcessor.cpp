#include "DelayProcessor.h"


DelayProcessor::DelayProcessor()
: sampleRate(0), delay(0), delaySec(DELAY_DEFAULT_SEC), amount(AMOUNT_DEFAULT_PERCENT/100), feedback(FEEDBACK_DEFAULT_PERCENT/100)
{}

void DelayProcessor::initialize(float sampleRate){
	buffer.resize(DELAY_MAX_SEC*sampleRate);
	this->sampleRate = sampleRate;
	this->delay = delaySec * sampleRate; 
}
void DelayProcessor::setAmount(float amount){
	this->amount = amount;
}
void DelayProcessor::setFeedback(float feedback){
	this->feedback = feedback;
}
void DelayProcessor::setDelay(float seconds){
	delaySec = seconds;
	float delay = seconds * sampleRate;
	if (delay > DELAY_MAX_SEC*sampleRate){
		delay = DELAY_MAX_SEC*sampleRate;
	}
	this->delay = delay;
}

float DelayProcessor::processOneSample(float input){
	float delayedSample = buffer.readWithDelay(delay);
	buffer.write(input  + feedback * delayedSample);
	float output = amount * delayedSample + input;
	return output;
}
void DelayProcessor::process(float* input, float* output, int numberOfSamples){
	for(int i = 0; i < numberOfSamples; i++){
		output[i] = processOneSample(input[i]);
	}
}
