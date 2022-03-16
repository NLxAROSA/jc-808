#ifndef CLAP_H
#define CLAP_H

#include "filter.h"
#include "instrument.h"

class Clap : public Instrument
{
public:
    Clap();
    ~Clap() = default;

    void setDefaults() override;

    void setBandPassFilter(Filter *);
    void setHighPassFilter(Filter *);

    double getSample() override;

private:
    const std::string m_defaultName = "Clap";

    static const int m_defaultPitch = 200;

    // 10 ms between claps
    static constexpr double m_interval = 0.01;

    Filter *m_highPass;
    Filter *m_bandPass;
};

#endif
