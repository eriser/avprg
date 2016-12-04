#include "FlangerProcessor.h"


FlangerProcessor::FlangerProcessor()
: depth(0)
, sampleRate(0)
, delay(0)
, phase(0)
{
	setFrequency(FREQUENCY_DEFAULT_HZ);
	setDelay(DELAY_DEFAULT_SEC);
	setDepth(DEPTH_DEFAULT_PERCENT/100);
	setPhase(PHASE_DEFAULT_DEGREE / 180 * PI);
}

void FlangerProcessor::initialize(float sampleRate){
	this->sampleRate = sampleRate;
	lfo.initialize(sampleRate);
	buffer.resize(2 * DELAY_MAX_SEC * sampleRate);
}
void FlangerProcessor::setFrequency(float frequency){
	lfo.setFrequency(frequency);
}

void FlangerProcessor::setDepth(float depth){
	this->depth = depth;
}
void FlangerProcessor::setDelay(float delay){
	this->delay = delay * sampleRate;
}
void FlangerProcessor::setPhase(float phase){
	lfo.setPhase(phase);
}
float FlangerProcessor::processOneSample(float input){
	float lfoValue = lfo.getValue();		

	int maxDelay = DELAY_MAX_SEC * sampleRate;
	float delaySamples = delay + lfoValue * depth * maxDelay;
	float value = buffer.readWithDelay(delaySamples);

	buffer.write(input);

	return input + value;
}
void FlangerProcessor::process(float* input, float*output, int numberOfSamples){
	for(int i = 0; i < numberOfSamples; i++){
		output[i] = processOneSample(input[i]);
	}
}