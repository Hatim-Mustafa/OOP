#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream in("vehicles.txt");
    string str;
    if (!in) {
        cout << "file not opened\n";
        return 0;
    }
    while(getline(in, str)) {
        if(str[0] == '/' && str[1] == '/') {
            continue;
        }
        size_t pos = str.find(',');
        if (pos == string::npos) {
            continue;
        }
        string sub = str.substr(0, pos);
        if (sub == "AutonomousCar") {
            sub = str.substr(pos + 1, 5);
            pos = str.find(':') + 1;
            string s = str.substr(pos, 3);
            float num = stof(s);
            cout << sub << " " << num << endl;
        }
        else if (sub == "ElectricVehicle") {
            sub = str.substr(pos + 1, 5);
            pos = str.find(':') + 1;
            if (pos == string::npos) {
                cout << "not found\n";
            }
            else {
                string s = str.substr(pos, 3);
                int num = stoi(s);
                cout << sub << " " << num << endl;
            }
        }
    }
}