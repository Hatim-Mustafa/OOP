#include <iostream>
#include <string>
using namespace std;

class Patient {
    public:
    int id;
    string name;
    string* results;
    int numOfTests;

    Patient (int id, string na, string* r, int n) {
        this->id = id;
        this->name = na;
        this->numOfTests = n;
        this->results = new string[n];
        this->results = r;
    }

    ~Patient () {
        delete [] results;
    }

    Patient (Patient &obj) {
        this->id = obj.id;
        this->name = obj.name;
        this->numOfTests = obj.numOfTests;
        this->results = new string[this->numOfTests];
        for (int i = 0; i < numOfTests; i++) {
            this->results[i] = obj.results[i];
        }
    }

    void display () {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        for (int i = 0; i < numOfTests; i++) {
            cout << "Result " << i+1  << ": " << this->results[i] << endl;
        }
    }
};

int main () {
    string * r = new string[2];
    r[0] = "HIV pos";
    r[1] = "AIDS neg";
    Patient p1(1, "Hatim", r, 2);
    Patient p2(p1);

    p2.results[0] = "Something";
    p1.display();
    p2.display();
}