#include <iostream>
#include <string>
using namespace std;

class TourGuide {
    string name;
    int yoe;
    string specialization;

    public:
    TourGuide(string n, string s, int y) {
        name = n;
        specialization =s;
        yoe = y;
    }

    void displayDetails () {
        cout << "Name: " << name << endl;
        cout << "Specialization " << specialization << endl;
        cout << "Years of Experience: " << yoe << endl;
    }
};

class TravelAgency {
    TourGuide** guideList;
    int numOfGuides;

    public:
    TravelAgency (int n, TourGuide** t) {
        numOfGuides = n;
        guideList = t;
    }

    void displayDetails () {
        cout << "List of TourGuides\n";
        for (int i = 0; i < numOfGuides; i++) {
            guideList[i]->displayDetails();
            cout << endl;
        }
    }
};

int main () {
    TourGuide** t;
    int n = 3;
    t = new TourGuide*[n];
    t[0] = new TourGuide("Nathan", "abc", 3);
    t[1] = new TourGuide("Alice", "def", 5);
    t[2] = new TourGuide("Bob", "ghi", 2);

    TravelAgency travellers (n, t);
    travellers.displayDetails();

    for (int i = 0; i < n; i++) {
        delete t[i];
    }
    delete [] t;
}

