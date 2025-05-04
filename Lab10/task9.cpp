#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main () {
    ifstream in("large_log.txt");
    string s;
    getline(in, s);
    cout << s << endl;
    cout << in.tellg() << endl;
    getline(in, s);
    cout << s << endl;
    cout << in.tellg() << endl;
}