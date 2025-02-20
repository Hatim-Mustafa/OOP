#include <iostream>
#include <string>
using namespace std;

class Battery {
    int mAh;

    public:
    Battery () {
        mAh = 1000;
    }
    Battery(int m) {
        mAh = m;
    }

    void displayDetails () {
        cout << "Battery Power: " << mAh << "mAh" << endl;
    }
};

class MobilePhone {
    Battery battery;
    int model;
    string company;

    public:
    MobilePhone (int m, Battery b, string c) {
        company = c;
        model = m;
        battery = b;
    }

    void displayDetails () {
        cout << "Company: " << company << endl;
        cout << "Model: " << model << endl;
        battery.displayDetails();
    }
};

int main () {
    Battery b(5000);
    MobilePhone p(1234, b, "Huawei");

    p.displayDetails();
}

