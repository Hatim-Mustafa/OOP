#include <iostream>
using namespace std;

class Vehicle {
    public:
    string brand;
    int speed;

    Vehicle(string n, int s) {
        brand = n;
        speed = s;
    }

    void displayDetails () {
        cout << "brand: " << brand << endl;
        cout << "speed: " << speed << endl;
    }
};

class Car: public Vehicle {
    public:
    int seats;

    Car (string n, int s, int seat) : Vehicle(n, s), seats(seat) {}

    void displayDetails () {
        Vehicle::displayDetails();
        cout << "seats: " << seats << endl;
    }
};

class ElectricCar: public Car {
    public:
    int batteryLife;

    ElectricCar(string n, int s, int seat, int b) : Car(n, s, seat), batteryLife(b) {}

    void DisplayDetails () {
        Car::displayDetails();
        cout << "battery life: " << batteryLife << endl;
    }
};

int main () {
    ElectricCar car("tesla", 30, 2, 6);
    car.DisplayDetails();
}