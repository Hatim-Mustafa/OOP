#include <fstream>
#include <iostream>
using namespace std;

int main () {
    ofstream out("sensor_log.txt");
    size_t pos = out.tellp();
    cout << pos << endl;

    string s = "Sensor 1: 25.5 C";
    out << s << endl;
    pos = out.tellp();
    cout << pos << endl;

    s = "Sensor 2: 98.1%RH";
    out << s << endl;
    pos = out.tellp();
    cout << pos << endl;
}