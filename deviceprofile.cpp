#include "deviceprofile.h"

deviceProfile::deviceProfile(int deviceId, double batteryLevel)
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
