#ifndef ENVELOPE_H
#define ENVELOPE_H


class EnvelopeSection{
public:
    void initialize (float sampleRate);
    void setStartDb(float dB);
    void setStopDb(float dB);
    void setDuration(float seconds);
    void start();
    void stop();
    void getValue();
private:
    float sampleRate;
    float start_dB;
    float end_dB;
    float durationSeconds;
    float time;
};

class Envelope
{
public:
    enum State{OFF, ATTACK, DECAY, SUSTAIN, RELEASE};
    Envelope();
    void setSampleRate(float sampleRate);
    void on();
    void off();
    float process(float input);
    void setReleaseSeconds(float seconds);
    void setAttackSeconds(float seconds);
    void setDecaySeconds(float seconds);
    void setSustain_dB(float sustain_dB);
private:
    void setState(State state);
private:
    State state;
    float sampleRate;
    float gain;
    float gainChange;
    float releaseSeconds;
    float attackSeconds;
    float decaySeconds;
    float sustain_dB;
    float sustainGain;
};

#endif // ENVELOPE_H
