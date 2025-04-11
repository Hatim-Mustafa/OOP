#include <iostream>
using namespace std;

class Humidity;

class Temperature {
    private: 
    float temp;

    public:
    Temperature (): temp(32) {}

    friend float calculateHeatIndex(Temperature& t, Humidity& h);
};

class Humidity {
    private:
    float humidity;

    public:
    Humidity (): humidity(0.7) {}

    friend float calculateHeatIndex(Temperature& t, Humidity& h);
};

float calculateHeatIndex (Temperature& t, Humidity& h) {
    return t.temp * h.humidity;
}

int main () {
    Temperature t;
    Humidity h;
    cout << "Heat Index: " << calculateHeatIndex(t, h) << endl;
}