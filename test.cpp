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

   Wave alpha2(10, 2, "alpha");
   Wave beta2(14, 2, "beta");
   Wave delta2(1, 2, "delta");
   Wave theta2(5, 2, "theta");


   // Define sample electrodes
   Electrode electrodes[] = {
       Electrode(alpha, beta, delta, theta),
       Electrode(alpha, beta, delta, theta),
       Electrode(alpha, beta, delta, theta),
       Electrode(alpha, beta, delta, theta),
       Electrode(alpha2, beta2, delta2, theta2)// Sample electrode 1
//        {15, 25, 35, 45, 55, 65, 75, 85}, // Sample electrode 2
       // Add more sample electrodes as needed
   };
   int numElectrodes = sizeof(electrodes) / sizeof(electrodes[0]);

//    Electrode [] *elctrodesPtr = &

   // Create a session object
   Session session(electrodes, numElectrodes);



}



