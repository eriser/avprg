#ifndef OSCILLATOR_H
#define OSCILLATOR_H

class Oscillator
{
public:
	Oscillator();
	~Oscillator(void);
	void initialize(float sampleRate);
	void setFrequency(float setFrequency);
	float getValue();

private:
	int index;
	float sampleRate;
	float frequency;
};

#endif