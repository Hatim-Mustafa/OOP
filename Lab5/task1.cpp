#include <iostream>
#include <string>
using namespace std;

class Car {
    public:
    static int carCount;
    int regNum;
    string model;
    string owner;

    public:
    Car(string name, string m) : regNum(carCount++), owner(name), model(m) {}

    Car(Car &obj) {
        cin.ignore();
        this->model = obj.model;
        this->regNum = obj.regNum;
        cout << "Enter your name: ";
        getline(cin, this->owner);
    }

    void display () {
        cout << "Registration Number: " << regNum << endl;
        cout << "Model: " << model << endl;
        cout << "Owner name: " << owner << endl;
    }
};

int Car::carCount = 0;

int main () {
    int id;
    Car car1("Harold", "123D");
    Car car2("Gerald", "5623D");

    cout << "Which car do you want to rent?\n";
    car1.display();car2.display();
    cin >> id;
    if (car1.regNum == id) {
        car1 = Car(car1);
    }
    else if (car2.regNum == id) {
        car2 = Car(car2);
    }

    cout << "Which car do you want to rent?\n";
    car1.display();car2.display();

}