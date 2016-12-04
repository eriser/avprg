#ifndef OSCILLATOR_PROCESSOR_H
#define OSCILLATOR_PROCESSOR_H
#include "Oscillator.h"
class OscillatorProcessor{
public:
	OscillatorProcessor();
	void initialize(float sampleRate);
	void noteOn(int pitch, int velocity);
	void noteOff();
	float processOneSample();
	void process(float*output, int numberOfSamples);
	void setGain(float gain);
private:
	float sampleRate;
	bool isNoteOn;
	int pitch;
	int velocity;
	float gain;
	Oscillator oscillator;
};
#endif