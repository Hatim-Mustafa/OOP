#include <iostream>
using namespace std;

//All new marker pens will have an ink level of MAX;
const int MAX = 100;

class Planner {

    public:
        string brand;
        string color;
    private:
        float inkLvl;
        bool refillability;

    public:
        Planner (string b, string c, bool r) {
            brand = b;
            color = c;
            inkLvl = MAX;
            refillability = r;
        }

        float showInkLvl () {return inkLvl;}

        void write(int numOfWords) {
            if (inkLvl > numOfWords) {
                cout << numOfWords << " words have been written\n";
                inkLvl -= numOfWords;
            }
            else {
                cout << "Not Enough Ink\n";
                refill();
            }
        }

        bool isRefiilable () {return refillability;}

        void refill () {
            if (isRefiilable()) {
                inkLvl = MAX;
                cout << "Pen has been refilled\n";
            }
            else {
                cout << "Cannot be refilled\n";
            }
        }
};

int main () {
    Planner pen ("Signature", "blue", true);

    pen.write(60);
    if (pen.showInkLvl() < 20) {
        pen.refill();
    }
    pen.write(50);
    cout << "Pen Ink Level is " << pen.showInkLvl() << endl;

    Planner pen2 ("Signature", "blue", false);
    pen2.write(90);
    if (pen2.showInkLvl() < 20) {
        pen2.refill();
    }
}