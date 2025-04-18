#include <iostream>
#include <string>
using namespace std;

class Activity{
    protected:
    public:
    virtual void calculateCaloriesBurned()=0;
};

class Running:public Activity{
    private:
    double distance,time;

    public:
    Running(double d, double t) : distance(d), time(t) {}

    void calculateCaloriesBurned()override{
       cout<<"enter weight: ";
       float w;
       cin>>w;
       cout<<"calories burned: "<<time*distance*w<<endl;
    }
};

class Cycling:public Activity{
    private:
    double speed,time;

    public:
    Cycling(double s, double t) : speed(s), time(t) {}

    void calculateCaloriesBurned()override{
        cout<<"enter weight: ";
        float w;
        cin>>w;
        cout<<"calories burned: "<<time*speed*w<<endl;
    }
};

int main(){
    Running r(1.5,10);
    Cycling c(15,2);
    r.calculateCaloriesBurned();
    c.calculateCaloriesBurned();
}