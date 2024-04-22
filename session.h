#ifndef SESSION_H
#define SESSION_H

#include "electrode.h"
#include <cstdio>
#include <vector>
#include <QDebug>
#include <random>
#include <future>
#include <QObject>
#include <QTimer>
#include <QDateTime>

class Session : public QObject {
   Q_OBJECT
public:
  // Constructor
  explicit Session(Electrode electrodes[], int size);
  QDateTime getSessionStartTime() const;

   void treatmentRound(int offsetHz, int roundNum);
   int calculateBaseline(std::vector<Electrode>& electrodes, int size); // c: unused
   int getOverallAverageDominantFreq() { return overallAverageDominantFreq; };
   int getFrequency(int, int);
   int getDominantFrequency(int, int);
   double getAvgDominantFrequency(int);

//   void startSessionProcess();
  //void treatmentRound(QVector<Electrode>& electrodes, int offsetHz, int roundNum);
  void calculateElectrodeFrequencies(QVector<Electrode>& electrodes);
  //int calculateBaseline(QVector<Electrode>& electrodes, int size);
  //void applyTreatmentFunc(Electrode& electrode, int offsetHz);

//   void treatmentRound(int offsetHz, int roundNum);
//   int calculateBaseline();
  //int getOverallAverageDominantFreq() { return overallAverageDominantFreq; };
  QTimer* getTimer() { return timer; }
  bool getPaused() { return paused; }
//   void pause();
//   void resume();

signals:
   void sessionStarted();
   void treatmentStarted();
   void treatmentPaused();

public slots:
   void startSession();

//private slots:
//    void continueTreatment();

private:
   int overallAverageDominantFreq;
   // Helper function to apply treatment concurrently
   QVector<Electrode>electrodesVec1;
//   int overallAverageDominantFreq;
    QTimer *timer;
    QDateTime startTime;
   int numElectrodes;
//   int currentRound;
//   int currentOffset;
     std::atomic<bool> paused;
//   QVector<Electrode> electrodesVec;

//   void treatmentRound(int offsetHz, int roundNum);
//   int calculateBaseline();
  // Helper function to apply treatment concurrently
};

#endif // SESSION_H






