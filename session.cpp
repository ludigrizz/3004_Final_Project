#include "session.h"

Session::Session(Electrode electrodes[], int size) {
    // Convert array to vector for flexibility
    std::vector<Electrode> electrodesVec(electrodes, electrodes + size);

    printf("Calculating dominant frequency... \n");

    // get overall dominant freq 
    int totalDominantFreq = 0;
    for (const auto& electrode : electrodesVec) {
        totalDominantFreq += electrode.getDominantFrequency();
    }
    int averageDominantFreq = totalDominantFreq / size;
    
    printf("Overall average dominant frequency is %s Hz.\n", averageDominantFreq);

    // Apply treatment concurrently
    applyTreatmentConcurrently(electrodesVec, 5);
    applyTreatmentConcurrently(electrodesVec, 10);
    applyTreatmentConcurrently(electrodesVec, 15);
    applyTreatmentConcurrently(electrodesVec, 20);
}

void Session::applyTreatmentConcurrently(std::vector<Electrode>& electrodes, int x) {
    // Define lambda function for concurrent treatment
    auto treatmentFunc = [x](Electrode& electrode) {
        electrode.applyTreatment(x);
    };

    // Create threads for each electrode
    std::vector<std::thread> threads;
    for (auto& electrode : electrodes) {
        threads.emplace_back(treatmentFunc, std::ref(electrode));
    }

    // Join threads to wait for their completion
    for (auto& thread : threads) {
        thread.join();
    }
}