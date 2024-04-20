#include "session.h"


Session::Session(Electrode electrodes[], int size, QObject *parent) :
   QObject(parent), numElectrodes(size), electrodesVec(electrodes, electrodes + size){

}
void Session::startSession() {
   emit sessionStarted();

   qDebug().nospace() << "Overall average dominant frequency (DRF) at start of session is " << calculateBaseline(electrodesVec, numElectrodes);

   // Apply treatment concurrently
   treatmentRound(electrodesVec, 5, 1);
   treatmentRound(electrodesVec, 10, 2);
   treatmentRound(electrodesVec, 15, 3);
   treatmentRound(electrodesVec, 20, 4);

   qDebug().nospace() << "Overall average dominant frequency (DRF) at end of session is " << calculateBaseline(electrodesVec, numElectrodes);


}

//void Session::pause() {
//    emit treatmentPaused();
//    if (!paused) {
//        qDebug() << "Session paused";
//        paused = true;
//    }
//}

//void Session::resume() {
//    if (paused) {
//        qDebug() << "Session resumed";
//        paused = false;
//        for (int round = currentRound; round <= 4; ++round) {
//            treatmentRound(electrodesVec, currentOffset, round);
//            if(paused) {
//                break;
//            }
//            ++currentRound;
//            currentOffset += 5;
//        }
//    }
//}

QDateTime Session::getSessionStartTime() const {
   return startTime;
}

void Session::treatmentRound(QVector<Electrode>& electrodes, int offsetHz, int roundNum) {
   treatmentStarted();
   qDebug().nospace() << "***Start of Round " << roundNum << "***";

   // Define lambda function for concurrent treatment
   auto treatmentFunc = [offsetHz](Electrode& electrode) {
       electrode.applyTreatment(offsetHz);
   };

   // Create threads for each electrode treatment
   std::vector<std::thread> treatmentThreads;
   for (auto& electrode : electrodes) {
       treatmentThreads.emplace_back(treatmentFunc, std::ref(electrode));
   }

   // Join threads to wait for treatment completion
   for (auto& thread : treatmentThreads) {
       thread.join();
   }

   calculateElectrodeFrequencies(electrodes);


   qDebug().nospace() << "***End of " << roundNum << "***";
}

void Session::calculateElectrodeFrequencies(QVector<Electrode>& electrodes) {

   // Define lambda function for obtaining dominant frequency
   auto calculateFunc = [](Electrode& electrode) {
       electrode.getDominantFrequency();
       qDebug().nospace() << "Electrode DRF is " << electrode.getDominantFrequency();
   };

   // Create threads for obtaining dominant frequency
   std::vector<std::thread> frequencyThreads;
   for (auto& electrode : electrodes) {
       frequencyThreads.emplace_back([calculateFunc, &electrode]() { calculateFunc(electrode); });
   }

   // Join threads to wait for frequency calculation
   for (auto& thread : frequencyThreads) {
       thread.join();
   }

}

int Session::calculateBaseline(QVector<Electrode>& electrodesVec, int size) {
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









