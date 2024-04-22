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

//    bool paused = false;
//    bool stopCurrentRound = false;
//    int currentRound = 0;
public:
  // Constructor
  explicit Session(Electrode electrodes[], int size, QObject *parent = nullptr);
  QDateTime getSessionStartTime() const;

   void treatmentRound(int offsetHz, int roundNum);
   int calculateBaseline(std::vector<Electrode>& electrodes, int size); // c: unused
   int getOverallAverageDominantFreq() { return overallAverageDominantFreq; };
   int getFrequency(int, int);
   int getDominantFrequency(int, int);
   double getAvgDominantFrequency(int);

//   void startSessionProcess();
  void treatmentRound(QVector<Electrode>& electrodes, int offsetHz, int roundNum);
  void calculateElectrodeFrequencies(QVector<Electrode>& electrodes, int roundNum);
  int calculateBaseline(QVector<Electrode>& electrodes, int size);
  void applyTreatmentFunc(Electrode& electrode, int offsetHz);


//   void treatmentRound(int offsetHz, int roundNum);
//   int calculateBaseline();
  int getOverallAverageDominantFreq() { return overallAverageDominantFreq; };
  QTimer* getTimer() { return timer; }
  bool getPaused() { return paused; }
  void pauseResumeSession();
  void resumeSession();
  void startPrintOverallAvgDomFreq();
  void endPrintOverallAvgDomFreq();
  void scheduleFromRound(int startRound);

signals:
   void sessionStarted();
   void treatmentAdministering();

   void treatmentAdministrationDone();
   void sessionEnded();
   void treatmentPaused();
   void sessionPaused();
   void sessionResumed();

public slots:
   void startSession();
   void stopSession();

private:
  int overallAverageDominantFreq;
  QTimer *timer;
  QDateTime startTime;
  int numElectrodes;
  int currentOffset;
//   std::atomic<bool> paused;
  QVector<Electrode> electrodesVec;
  bool paused = false;
  bool stopCurrentRound = false;
  int currentRound = 0;


};

#endif // SESSION_H






