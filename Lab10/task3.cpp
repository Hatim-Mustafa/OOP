#include <fstream>
#include <sstream>
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
        if(str[0] == '/' && str[1] == '/' || str == "") {
            continue;
        }
        istringstream ins(str);
        string data;
        while(getline(ins, data, ',')) {
            try{
                int num = stoi(data);
                cout << num << endl;
            }
            catch (const invalid_argument& e) {}
        }
        cout << endl;
    }
}