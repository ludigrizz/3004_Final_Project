#include "session.h"

Session::Session(Electrode electrodes[], int size) {

     numElectrodes = size;

    electrodesVec1.reserve(size);

    //Convert array to vector for flexibility
    for (int i = 0; i < size; ++i) {
        electrodesVec1.append(electrodes[i]);
    }

    
}
void Session::startSession() {
   emit sessionStarted();

   //qDebug().nospace() << "Overall average dominant frequency (DRF) at start of session is " << calculateBaseline(electrodesVec1, numElectrodes);

   // Convert array to vector for flexibility
   //std::vector<Electrode> electrodesVec(electrodes, electrodes + size); //c: unused
  // qDebug().nospace() << "Overall average dominant frequency (DRF) at end of session is " << calculateBaseline(electrodesVec, numElectrodes);

  // qDebug().nospace() << "Overall average dominant frequency (DRF) at start of session is " << calculateBaseline(electrodesVec, size);

   // Apply treatment concurrently
//   treatmentRound(electrodesVec, 5, 1);
//   treatmentRound(electrodesVec, 10, 2);
//   treatmentRound(electrodesVec, 15, 3);
//   treatmentRound(electrodesVec, 20, 4);

   //qDebug().nospace() << "Overall average dominant frequency (DRF) at end of session is " << calculateBaseline(electrodesVec, size);
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


void Session::treatmentRound(int offsetHz, int roundNum) {
   treatmentStarted();
   qDebug().nospace() << "***Start of Round " << roundNum << "***";

   // Define lambda function for concurrent treatment
   auto treatmentFunc = [offsetHz](Electrode& electrode) {
       electrode.applyTreatment(offsetHz);
   };

   // Create threads for each electrode treatment
   std::vector<std::thread> treatmentThreads;
   for (auto& electrode : electrodesVec1) {
       treatmentThreads.emplace_back(treatmentFunc, std::ref(electrode));
   }

   // Join threads to wait for treatment completion
   for (auto& thread : treatmentThreads) {
       thread.join();
   }

   calculateElectrodeFrequencies(electrodesVec1);


   qDebug().nospace() << "***End of " << roundNum << "***";
}

void Session::calculateElectrodeFrequencies(QVector<Electrode>& electrodes) {
  
   auto getFrequencyFunc = [](Electrode& electrode) {
       electrode.calculateDominantFrequency();
       //qDebug().nospace() << "Electrode DRF is " << electrode.getDominantFrequency();

   // Define lambda function for obtaining dominant frequency
//    auto calculateFunc = [](Electrode& electrode) {
//        electrode.getDominantFrequency();
//        qDebug().nospace() << "Electrode DRF is " << electrode.getDominantFrequency();

   };

   // Create threads for obtaining dominant frequency
   std::vector<std::thread> frequencyThreads;
   for (auto& electrode : electrodesVec1) {
       frequencyThreads.emplace_back(getFrequencyFunc, std::ref(electrode));
   };

//    for (auto& electrode : electrodes) {
//        frequencyThreads.emplace_back([calculateFunc, &electrode]() { calculateFunc(electrode); });
//    }


   // Join threads to wait for frequency calculation
   for (auto& thread : frequencyThreads) {
       thread.join();
   }

}



/* c: unused function below*/

int Session::calculateBaseline(std::vector<Electrode>& electrodesVec, int size) {
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

}

int Session::getDominantFrequency(int index, int t_id) {
    return electrodesVec1.at(index).getDominantFrequency(t_id);
}

double Session::getAvgDominantFrequency(int index) {
    return electrodesVec1.at(index).getAvgDominantFrequency();
}







