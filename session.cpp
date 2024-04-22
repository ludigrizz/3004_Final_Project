#include "session.h"

Session::Session(Electrode electrodes[], int size) {

    electrodesVec1.reserve(size);
    
}
void Session::scheduleFromRound(int startRound) {
   if (startRound < 1 || startRound > 4) {
       qDebug() << "Invalid start round provided: " << startRound;
       return;
   }

   for (int i = startRound; i <= 4; ++i) {
       int delayBase = 6000 * (i - 1);
       QTimer::singleShot(delayBase + 1000, this, [this, i]() {
           if (!paused) treatmentRound(electrodesVec, 5 * i, i);
       });
       QTimer::singleShot(delayBase + 2000, this, [this, i]() {
           if (!paused) calculateElectrodeFrequencies(electrodesVec, i); }
       );
   }

   // Handle specific timing edge cases if necessary
   if (startRound == 1) {
       QTimer::singleShot(0, this, [&]() {
           if (!paused) startPrintOverallAvgDomFreq();
       });
       QTimer::singleShot(30000, this, [&]() {
           if(!paused) endPrintOverallAvgDomFreq();
       });
   }
}

void Session::startSession() {
   emit sessionStarted();
   scheduleFromRound(1);
}

void Session::startPrintOverallAvgDomFreq() {
   qDebug().nospace() << "Overall average dominant frequency (DRF) at start of session is " << calculateBaseline(electrodesVec, numElectrodes);

}
void Session::endPrintOverallAvgDomFreq() {
   qDebug().nospace() << "Overall average dominant frequency (DRF) at end of session is " << calculateBaseline(electrodesVec, numElectrodes);
}

void Session::stopSession() {
   emit sessionEnded();
}

void Session::pauseResumeSession() {
   emit sessionPaused();
   if (!paused) {
       paused = true;
       stopCurrentRound = true;
   }
   if (paused) {
       paused = false;
       if (currentRound > 0) {
           scheduleFromRound(currentRound);
       }
   }
}

void Session::resumeSession() {

}

QDateTime Session::getSessionStartTime() const {
   return startTime;
}

void Session::treatmentRound(QVector<Electrode>& electrodes, int offsetHz, int roundNum) {
   if (paused || stopCurrentRound) {
       return;
   }
   currentRound = roundNum;
   emit treatmentAdministering();

   qDebug().nospace() << "***Start of Round " << roundNum << "***";
   qDebug().nospace() << "Administering treatment...";

   std::vector<std::thread> treatmentThreads;
   for (auto& electrode : electrodes) {
       treatmentThreads.push_back(std::thread([&, offsetHz](){
           if (!paused) electrode.applyTreatment(offsetHz);
       }));

   }

   // Join threads to wait for treatment completion
   for (auto& thread : treatmentThreads) {
       if (thread.joinable()) {
           thread.join();
       }
   }
}

void Session::calculateElectrodeFrequencies(QVector<Electrode>& electrodes, int roundNum) {


   if (!paused) emit treatmentAdministrationDone();

   std::vector<std::thread> calculateThreads;
   for (auto& electrode : electrodes) {
       calculateThreads.push_back(std::thread([&](){
           if (!paused) {
               electrode.getDominantFrequency();
               qDebug().nospace() << "Electrode DRF is " << electrode.getDominantFrequency();
           }
       }));
   }


   // Join threads to wait for treatment completion
   for (auto& thread : calculateThreads) {
       if (thread.joinable()) {
           thread.join();
       }
   }
   qDebug().nospace() << "***End of " << roundNum << "***";

}



/* c: unused function below*/

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


int Session::getFrequency(int index, int time) {
    return electrodesVec1.at(index).getFrequency(time);

// int Session::calculateBaseline(QVector<Electrode>& electrodesVec, int size) {
//   // Vector to hold futures for each electrode calculation
//   std::vector<std::future<void>> futures;

//   // Calculate dominant frequency for each electrode concurrently
//   for (auto& electrode : electrodesVec) {
//       // Start a thread for calculating dominant frequency for each electrode
//       futures.emplace_back(std::async(std::launch::async, &Electrode::calculateDominantFrequency, &electrode));
//   }

//   // Wait for all threads to finish
//   for (auto& future : futures) {
//       future.wait();
//   }

//   // Calculate total dominant frequency
//   int totalDominantFreq = 0;
//   for (auto& electrode : electrodesVec) {
//       totalDominantFreq += electrode.getDominantFrequency();
//   }

//   // Calculate overall average dominant frequency
//   overallAverageDominantFreq = totalDominantFreq / size;

//   return overallAverageDominantFreq;

// }

int Session::getDominantFrequency(int index, int t_id) {
    return electrodesVec1.at(index).getDominantFrequency(t_id);
}

double Session::getAvgDominantFrequency(int index) {
    return electrodesVec1.at(index).getAvgDominantFrequency();
}







