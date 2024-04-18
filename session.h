#ifndef SESSION_H
#define SESSION_H

#include "electrode.h"
#include <cstdio> 
#include <vector>
#include <QDebug>

class Session {
public:
    // Constructor
    Session(Electrode electrodes[], int size);

    void treatmentRound(std::vector<Electrode>& electrodes, int x);
    void calculateDominantFrequency();


private:
    // Helper function to apply treatment concurrently
};

#endif // SESSION_H
