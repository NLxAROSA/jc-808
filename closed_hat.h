#ifndef CLOSED_HAT_H
#define CLOSED_HAT_H

#include <array>
#include "filter.h"
#include "instrument.h"

class ClosedHat : public Instrument
{
public:
    ClosedHat();
    ~ClosedHat() = default;

    void setDefaults() override;

    void setBandPassFilter(Filter *);
    void setHighPassFilter(Filter *);

    double getSample() override;

private:
    const std::string m_defaultName = "Closed Hi-Hat";

    static const int m_basePitch = 40;

    std::array<double, 6> m_harmonics;

    Filter *m_bandPass;
    Filter *m_highPass;
};

#endif
