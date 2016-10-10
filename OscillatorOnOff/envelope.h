#ifndef ENVELOPE_H
#define ENVELOPE_H


class Envelope
{
public:
    Envelope();
    void setSampleRate(float sampleRate);
    float process(float input);
    void on();
    void off();
private:
    float sampleRate;
    float gain;
};

#endif // ENVELOPE_H
