#include <iostream>
#include <string>
using namespace std;

class Vehicle {
    protected:
    string model;
    float rate;

    public:
    Vehicle(string m, float r): model(m), rate(r) {}
    virtual float getDailyRate() = 0;
    virtual void displayDetail() = 0;
};

class Car : public Vehicle {
    public:
    Car(string m, float r) : Vehicle(m, r) {}

    float getDailyRate() override { 
        return rate;
    }

    void displayDetail() override {  
        cout << "Car Model: " << model << endl;
        cout << "Daily Rate: $" << rate << endl;
    }
};

    
class Bike : public Vehicle {
    public:
    Bike(string m, float r) : Vehicle(m, r) {}

    float getDailyRate() override { 
        return rate;
    }

    void displayDetail() override {  
        cout << "Bike Model: " << model << endl;
        cout << "Daily Rate: $" << rate << endl;
    }
};

int main() {
    Car myCar("Honda Civic", 55.0);
    Bike b("Royal Enfield",30);
    myCar.displayDetail();
    b.displayDetail();
}