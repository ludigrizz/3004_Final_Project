#ifndef DEVICEPROFILE_H
#define DEVICEPROFILE_H


class deviceProfile
{
public:
    deviceProfile(int, double);
    int getDeviceId();
    void setBatteryLevel(double);
    double getBatteryLevel();

private:
    int deviceId;
    double batteryLevel;
};

#endif // DEVICEPROFILE_H
