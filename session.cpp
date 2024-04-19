#include "session.h"

Session::Session(Electrode electrodes[], int size) {
   // Convert array to vector for flexibility
   std::vector<Electrode> electrodesVec(electrodes, electrodes + size);

   qDebug().nospace() << "Overall average dominant frequency (DRF) at start of session is " << calculateBaseline(electrodesVec, size);

   // Apply treatment concurrently
   treatmentRound(electrodesVec, 5, 1);
   treatmentRound(electrodesVec, 10, 2);
   treatmentRound(electrodesVec, 15, 3);
   treatmentRound(electrodesVec, 20, 4);

   qDebug().nospace() << "Overall average dominant frequency (DRF) at end of session is " << calculateBaseline(electrodesVec, size);



}

void Session::treatmentRound(std::vector<Electrode>& electrodes, int offsetHz, int roundNum) {
   qDebug().nospace() << "***Start of Round " << roundNum << "***";
   qDebug().nospace() << "Applying Treatment... ";

   // Define lambda function for concurrent treatment
   auto treatmentFunc = [offsetHz](Electrode& electrode) {
       electrode.applyTreatment(offsetHz);
   };

   // Create threads for each electrode
   std::vector<std::thread> treatmentThreads;
   for (auto& electrode : electrodes) {
       treatmentThreads.emplace_back(treatmentFunc, std::ref(electrode));
   }

   // Join threads to wait for their completion
   for (auto& thread : treatmentThreads) {
       thread.join();
   }


   qDebug().nospace() << "Treatment complete, computing new baselines... ";


   auto getFrequencyFunc = [](Electrode& electrode) {
       electrode.calculateDominantFrequency();
       qDebug().nospace() << "Electrode DRF is " << electrode.getDominantFrequency();
   };

   std::vector<std::thread> frequencyThreads;
   for (auto& electrode : electrodes) {
       frequencyThreads.emplace_back(getFrequencyFunc, std::ref(electrode));
   };

   for (auto& thread : frequencyThreads) {
       thread.join();
   }


   qDebug().nospace() << "***End of " << roundNum << "***";
}

int Session::calculateBaseline(std::vector<Electrode>& electrodesVec, int size) {
   // Vector to hold futures for each electrode calculation
   std::vector<std::future<void>> futures;

   // Calculate dominant frequency for each electrode concurrently
   for (auto& electrode : electrodesVec) {
       // Start a thread for calculating dominant frequency for each electrode
       futures.emplace_back(std::async(std::launch::async, &Electrode::calculateDominantFrequency, &electrode));
   }

   // Wait for all threads to finish
   for (auto& future : futures) {
       future.wait();
   }

   // Calculate total dominant frequency
   int totalDominantFreq = 0;
   for (auto& electrode : electrodesVec) {
       totalDominantFreq += electrode.getDominantFrequency();
   }

   // Calculate overall average dominant frequency
   overallAverageDominantFreq = totalDominantFreq / size;

   return overallAverageDominantFreq;
}





