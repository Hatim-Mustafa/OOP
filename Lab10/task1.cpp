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
        if(str[0] == '/' && str[1] == '/' || str == "") {
            continue;
        }
        cout << str << endl;
    }
}