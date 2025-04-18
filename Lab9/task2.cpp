#include <iostream>
 #include <string>
 using namespace std;

 class SmartDevice{
    public:
    SmartDevice() {}
    virtual void turnOn()=0;
    virtual void turnOff()=0;
    virtual bool getStatus()=0;
 };

 class LightBulb:public SmartDevice{
    protected:
    bool isOn;
    int brightness;

    public:
    LightBulb(int t):brightness(t){isOn=false;}

    void turnOn()override{
        isOn=true;
    }

    void turnOff()override{
        isOn=false;
    }

    bool getStatus()override{
        return isOn;
    }
 };

 class Thermostat:public SmartDevice{
    protected:
    bool isOn;
    double temperature;

    public:
    Thermostat(double t):temperature(t){isOn=false;}

    void turnOn()override{
        isOn=true;
    }

    void turnOff()override{
        isOn=false;
    }

    bool getStatus()override{
        return isOn;
    }
 };
 
 int main(){
    Thermostat t(47);
    LightBulb lb(70);
    t.turnOn();
    cout<<"status: "<<t.getStatus()<<endl;
    t.turnOff();
    cout<<"status: "<<t.getStatus()<<endl;
    lb.turnOn();
    cout<<"status: "<<lb.getStatus()<<endl;
    lb.turnOff();
    cout<<"status: "<<lb.getStatus()<<endl;
 }