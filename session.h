#ifndef SESSION_H
#define SESSION_H

#include "electrode.h"
#include <cstdio>
#include <vector>
#include <QDebug>
#include <random>
#include <future>

class Session {
public:
   // Constructor
   Session(Electrode electrodes[], int size);

   void treatmentRound(std::vector<Electrode>& electrodes, int offsetHz, int roundNum);
   int calculateBaseline(std::vector<Electrode>& electrodes, int size);
   int getOverallAverageDominantFreq() { return overallAverageDominantFreq; };


private:
   int overallAverageDominantFreq;
   // Helper function to apply treatment concurrently
};

#endif // SESSION_H



