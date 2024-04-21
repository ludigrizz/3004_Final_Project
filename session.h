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

   void treatmentRound(int offsetHz, int roundNum);
   int calculateBaseline(std::vector<Electrode>& electrodes, int size); // c: unused
   int getOverallAverageDominantFreq() { return overallAverageDominantFreq; };
   int getFrequency(int, int);
   int getDominantFrequency(int, int);
   double getAvgDominantFrequency(int);



private:
   int overallAverageDominantFreq;
   // Helper function to apply treatment concurrently
   QVector<Electrode>electrodesVec1;
};

#endif // SESSION_H



