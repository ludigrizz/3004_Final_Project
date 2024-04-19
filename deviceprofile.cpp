#include "deviceprofile.h"
#include <QDate>

deviceProfile::deviceProfile(int deviceId, double batteryLevel, QDate* d)
{
    this->deviceId = deviceId;
    this->batteryLevel = batteryLevel;
}

int deviceProfile::getDeviceId()
{
    return deviceId;
}

double deviceProfile::getBatteryLevel()
{
    return batteryLevel;
}

void deviceProfile::setBatteryLevel(double newBatteryLevel)
{
    batteryLevel = newBatteryLevel;
}
