#ifndef ELECTRODE_H
#define ELECTRODE_H

#include <cmath>
#include <thread>
#include <QDebug>
#include <random>
#include "wave.h"

class Electrode {
public:
   // Constructor
   Electrode(Wave alpha, Wave beta, Wave delta, Wave theta);

   // Methods
   void calculateDominantFrequency() ;
   void applyTreatment(int x);

   // Getter
   int getDominantFrequency(int) const;
   void setDominantFrequency(int newDomFreq);
   int getFrequency(int) const;
   double getAvgDominantFrequency() const;

private:
   QVector<int> dominantFrequency;
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



