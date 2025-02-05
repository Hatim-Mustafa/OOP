#include <iostream>
using namespace std;

class Planner {

    public:
        string brand;
        string color;
        float capacity;
    private:
        float currentFillLvl;

    public:
        Planner (string b, string c, float cfl,float cap) {
            brand = b;
            color = c;
            currentFillLvl = cfl;
            capacity = cap;
        }

        float showCurrentFillLvl () {return currentFillLvl;}

        void sipTea() {
            if (currentFillLvl > 0) {
                cout << "Sip taken\n";
                currentFillLvl--;
            }
            else {
                cout << "Mug is empty\n";
                refill();
            }
        }

        void refill () {
            currentFillLvl = capacity;
            cout << "Mug is refilled\n";
        }

        bool IsEmpty () {
            if (currentFillLvl == 0) {
                return true;
            }
            else {
                return false;
            }
        }
};

int main () {
    Planner mug ("Tapal", "brown", 10, 100);
    for (int i = 0; i < 10; i++) {
        mug.sipTea();
    }
    if (mug.IsEmpty()) {
        mug.refill();
    }
}