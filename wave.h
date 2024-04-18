#ifndef WAVE_H
#define WAVE_H
#include <QString>


class Wave
{
public:
    Wave(int, int, QString);

    int getFrequency();
    int getAmplitude();
    QString getFrequencyBand();
private:
    int frequency;
    int amplitude;
    QString frequencyBand;
};

#endif // WAVE_H
