#ifndef OSCILLATORSOURCE_H
#define OSCILLATORSOURCE_H

#include <vector>

#include "audiosource.h"
#include "oscillator.h"
#include "envelope.h"
class OscillatorSource: public AudioSource
{
public:
    OscillatorSource();
    virtual const QAudioFormat& format() const;
    virtual qint64 read(float** buffer, qint64 numFrames);
    virtual void start();
    virtual void stop();
    void setSelectedOscillator(int index);
    void setFrequency(float frequency);
    void noteOn(int note);
    void noteOff();
    void setGain(float decibel);
    void setAttackSeconds(float value);
    void setDecaySeconds(float value);
    void setReleaseSeconds(float value);
    void setSustain_dB(float value);
private:
    float createSample();
private:
    QAudioFormat audioFormat;
    Oscillator oscillator;
    Envelope envelope;
};

#endif // OSCILLATORSOURCE_H
