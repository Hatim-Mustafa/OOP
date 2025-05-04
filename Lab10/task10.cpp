#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main () {
    ifstream in("data_records.txt");
    string s;
    in.seekg(16);
    getline(in, s);
    cout << s << endl;
}