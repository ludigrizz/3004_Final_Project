#ifndef ELECTRODE_H
#define ELECTRODE_H

#include <cmath>
#include <thread>
#include <QDebug>
#include "wave.h"

class Electrode {
public:
    // Constructor
    Electrode(Wave alpha, Wave beta, Wave delta, Wave theta);

    // Methods
    void calculateDominantFrequency();
    void applyTreatment(int x);

    // Getter
    int getDominantFrequency() const;

private:
    int dominantFrequency;
    int alphaFreq;
    int betaFreq;
    int deltaFreq;
    int thetaFreq;
    int alphaAmp;
    int betaAmp;
    int deltaAmp;
    int thetaAmp;
};

#endif // ELECTRODE_H
