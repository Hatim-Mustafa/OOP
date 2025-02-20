#include <iostream>
#include <string>
using namespace std;

class Professor {
    string name;
    string dept;

    public:
    Professor(string n, string d) {
        name = n;
        dept = d;
    }

    void displayDetails () {
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
    }
};

class University {
    Professor** profList;
    int numOfProf;

    public:
    University (int n, Professor** p) {
        numOfProf = n;
        profList = p;
    }

    void displayDetails () {
        cout << "List of Professors\n";
        for (int i = 0; i < numOfProf; i++) {
            profList[i]->displayDetails();
            cout << endl;
        }
    }
};

int main () {
    Professor** p;
    int n = 3;
    p = new Professor*[n];
    p[0] = new Professor("Nathan", "AI");
    p[1] = new Professor("Alice", "Data Science");
    p[2] = new Professor("Bob", "Cybersecurity");

    University uni (n, p);
    uni.displayDetails();

    for (int i = 0; i < n; i++) {
        delete p[i];
    }
    delete [] p;
}

