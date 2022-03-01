#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <cmath>
#include <optional>
#include <string>
#include "envelope.h"

class Instrument
{
public:
    Instrument(int freq, Envelope env);
    ~Instrument();

    virtual std::string getName();

    void trigger();
    void release();
    bool isTriggered();
    bool isPlaying();

    void updateBy(double time);

    virtual double getSample();

    static constexpr double TAU = M_PI * 2.0;

protected:
    int mFreq;
    Envelope mEnv;

    double mDuration;
    double mElapsed;

    bool mTriggered;
    bool mPlaying;
};

#endif
