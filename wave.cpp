#include "wave.h"

Wave::Wave(int f, int a, QString band) : frequency(f), amplitude(a), frequencyBand(band) {}

int Wave::getFrequency() { return frequency; }
int Wave::getAmplitude() { return amplitude; }
QString Wave::getFrequencyBand() { return frequencyBand; }
