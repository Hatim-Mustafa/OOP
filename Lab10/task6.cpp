#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    int id;
    char name[20];
};

int main () {
    Student s1;
    s1.id = 12;
    strcpy(s1.name,"hatim");

    ofstream out("inventory.dat", ios::binary);
    out.write(reinterpret_cast<char*>(&s1), sizeof(Student));
    out.close();

    ifstream in("inventory.dat", ios::binary);
    Student s2;
    in.read(reinterpret_cast<char*>(&s2), sizeof(Student));
    cout << s2.id << s2.name << endl;
    in.close();
}