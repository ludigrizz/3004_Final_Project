#include <iostream>
#include "wave.h"
#include "electrode.h"
#include "session.h"
#include <QDebug>

void testRun() {
    //Same waves
    Wave alpha(9, 2, "alpha");
    Wave beta(15, 2, "beta");
    Wave delta(2, 2, "delta");
    Wave theta(4, 2, "theta");


    // Define sample electrodes
    Electrode electrodes[] = {
        {alpha, beta, delta, theta}, // Sample electrode 1
//        {15, 25, 35, 45, 55, 65, 75, 85}, // Sample electrode 2
        // Add more sample electrodes as needed
    };
    int numElectrodes = sizeof(electrodes) / sizeof(electrodes[0]);

    // Create a session object
    Session session(electrodes, numElectrodes);

    // Optionally, print the dominant frequency of each electrode before and after the session
    for (int i = 0; i < numElectrodes; ++i) {
         qInfo("Some treatment is happening");
         qDebug().nospace() << "before treatment - electrode " << (i+1) << "dominant freq: " << electrodes[i].getDominantFrequency();

    }

    // Run the session on the array of electrodes
    // The treatment will be applied concurrently with different values
    // (5, 10, 15, 20) as specified in the constructor of Session class

    // Optionally, print the dominant frequency of each electrode after the session
    for (int i = 0; i < numElectrodes; ++i) {
        qDebug().nospace() << "After treatment - Electrode " << i+1 << " Dominant Frequency: " << electrodes[i].getDominantFrequency();
    }
}
