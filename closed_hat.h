#ifndef CLOSED_HAT_H
#define CLOSED_HAT_H

#include <array>
#include "filter.h"
#include "instrument.h"

class ClosedHat : public Instrument
{
public:
    ClosedHat();

    double getSample() override;

    std::string getName() override;

private:
    const std::string mName = "Closed Hi-Hat";

    static const int mBaseFreq = 40;

    static constexpr double mDuration = 0.27;

    std::array<double, 6> mHarmonics;

    Filter *mBandPass;
    Filter *mHighPass;
};

#endif
