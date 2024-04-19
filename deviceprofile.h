#ifndef DEVICEPROFILE_H
#define DEVICEPROFILE_H

#include <QDate>
#include <QShowEvent>
class deviceProfile
{
public:
    deviceProfile(int, double, QDate*);
    int getDeviceId();
    void setBatteryLevel(double);
    double getBatteryLevel();
    void getDate();
    void setDate(QDate * d);
    void showEventDate(QShowEvent * e);

private:
    int deviceId;
    double batteryLevel;
    QDate* date;
};

#endif // DEVICEPROFILE_H
