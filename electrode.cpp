#include "electrode.h"
#include <QRandomGenerator>
#include <QDebug>

//int Electrode::dominantFrequency = 0;

Electrode::Electrode(Wave alpha, Wave beta, Wave delta, Wave theta)
       : alphaFreq(alpha.getFrequency()), betaFreq(beta.getFrequency()), deltaFreq(delta.getFrequency()),
         thetaFreq(theta.getFrequency()), alphaAmp(alpha.getAmplitude()), betaAmp(beta.getAmplitude()),
         deltaAmp(alpha.getAmplitude()), thetaAmp(alpha.getAmplitude()) {

}

void Electrode::calculateDominantFrequency() {
//    qDebug().nospace() << "DOM" << dominantFrequency;
   std::this_thread::sleep_for(std::chrono::seconds(5));

   dominantFrequency.append((alphaFreq * pow(alphaAmp, 2) + betaFreq * pow(betaAmp, 2) +
                        deltaFreq * pow(deltaAmp, 2) + thetaFreq * pow(thetaAmp, 2)) /
                       (pow(alphaAmp, 2) + pow(betaAmp, 2) + pow(deltaAmp, 2) + pow(thetaAmp, 2)));

//    qDebug().nospace() << "DOM" << dominantFrequency;

}


void Electrode::applyTreatment(int x) {
   // Define lambda function for incremental addition
   auto addIncrementally = [x](int& freq) {
       double increment = x / 16.0;
       auto interval = std::chrono::milliseconds(62); // Total 16 intervals ~1 second
       for (int i = 0; i < 16; ++i) {
           freq += increment; //todo: print to console delivering the 1 sec feedback at 1/16 of dominant + offset
//            qInfo("x");
           std::this_thread::sleep_for(interval);
       }
   };

   // Create threads for each frequency update
   std::thread t1(addIncrementally, std::ref(alphaFreq));
   std::thread t2(addIncrementally, std::ref(betaFreq));
   std::thread t3(addIncrementally, std::ref(deltaFreq));
   std::thread t4(addIncrementally, std::ref(thetaFreq));

   // Join threads to wait for their completion
   t1.join();
   t2.join();
   t3.join();
   t4.join();

   // After treatment, reassign frequencies to random values within respective ranges
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<int> alphaDist(8, 13);
   std::uniform_int_distribution<int> betaDist(14, 20);
   std::uniform_int_distribution<int> deltaDist(0, 3);
   std::uniform_int_distribution<int> thetaDist(4, 7);

   alphaFreq = alphaDist(gen);
   betaFreq = betaDist(gen);
   deltaFreq = deltaDist(gen);
   thetaFreq = thetaDist(gen);

//    calculateDominantFrequency();
}

int Electrode::getDominantFrequency(int index) const {
   return dominantFrequency[index];
}

void Electrode::setDominantFrequency(int newDomFreq) {
   //dominantFrequency = newDomFreq;
}

double Electrode::getAvgDominantFrequency() const {
    double avg = 0;

    avg = (dominantFrequency[0] + dominantFrequency[1] + dominantFrequency[2] + dominantFrequency[3]) / 4.0;

    return avg;
}

/* generating random data for graph */
int Electrode::getFrequency(int time) const {
    int randomNumber = QRandomGenerator::global()->bounded(-150,150);

    qDebug() << "Random number between 1 and 30:" << randomNumber;

    return randomNumber;
}


