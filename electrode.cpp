#include "electrode.h"

Electrode::Electrode(Wave alpha, Wave beta, Wave delta, Wave theta)
        : alphaFreq(alpha.getFrequency()), betaFreq(beta.getFrequency()), deltaFreq(delta.getFrequency()),
          thetaFreq(theta.getFrequency()), alphaAmp(alpha.getAmplitude()), betaAmp(beta.getAmplitude()),
          deltaAmp(alpha.getAmplitude()), thetaAmp(alpha.getAmplitude()) {}

void Electrode::calculateDominantFrequency() {
    dominantFrequency = (alphaFreq * pow(alphaAmp, 2) + betaFreq * pow(betaAmp, 2) + 
                         deltaFreq * pow(deltaAmp, 2) + thetaFreq * pow(thetaAmp, 2)) /
                        (pow(alphaAmp, 2) + pow(betaAmp, 2) + pow(deltaAmp, 2) + pow(thetaAmp, 2));
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
    
}

int Electrode::getDominantFrequency() const {
    return dominantFrequency;
}
