#include <iostream>
using namespace std;

class Device {
    public:
    int deviceId;
    bool status;

    Device(int id, bool s) {
        deviceId = id;
        status = s;
    }

    void displayDetails () {
        cout << "Device ID: " << deviceId << endl;
        string val = status ? "True" : "False";
        cout << "Status: " << val << endl;
    }
};

class SmartPhone: virtual public Device {
    public:
    float screenSize;

    SmartPhone(int a, bool s, float ss): Device(a, s), screenSize(ss) {}

    void displayDetails () {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << endl;
    }
};

class SmartWatch: virtual public Device {
    public:
    bool heartRate;

    SmartWatch(int a, bool s, bool h): Device(a, s), heartRate(h) {}

    void displayDetails () {
        Device::displayDetails();
        string val = heartRate ? "True" : "False";
        cout << "Heart Rate Monitor: " << val << endl;
    }
};

class SmartWearable: public SmartPhone, public SmartWatch {
    public:
    int stepCounter;

    SmartWearable(int a, bool s, bool h, float ss, int sc): Device(a, s), SmartPhone(a, s, ss), SmartWatch(a, s, h), stepCounter(sc) {}

    void displayDetails () {
        SmartWatch::displayDetails();
        cout << "Screen Size: " << SmartPhone::screenSize << endl;
        cout << "Step Counter: " << stepCounter << endl;
    }
};

int main () {
    SmartWearable s(12, true, false, 120, 6);
    s.displayDetails();
}