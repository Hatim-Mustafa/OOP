#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main () {
    fstream file("config.txt", ios::in | ios::out);
    string s;
    while(getline(file, s)) {
        cout << s << endl;
    }
    file.clear();
    file.seekp(6); 
    file << "XXXXX";
    file.clear();
    file.seekg(0);
    while(getline(file, s)) {
        cout << s << endl;
    }
}