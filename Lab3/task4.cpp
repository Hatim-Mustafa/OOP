#include <iostream>
using namespace std;

class Laptop {
    public:
        string brand;
        string model;
        int RAM;
        int storage;
        string processor;
        bool on;

    public:
        Laptop (string b, string m, int r, int s, string p) {
            brand = b;
            model = m;
            RAM = r;
            storage = s;
            processor = p;
            on = false;
        }

        void turn_on () {
            on = true;
            cout << "Laptop turned on\n";
        }

        void turn_off () {
            on = false;
            cout << "Laptop turned off\n";
        }

        void run_program () {
            if (on) {
                cout << "Program is running\n"; 
            }
            else {
                cout << "Cannot run program because laptop is turned off\n";
            }
        }

        void specs () {
            cout << "Brand name is " << brand << endl;
            cout << "Model is " << model << endl;
            cout << "RAM (in GB) is " << RAM << endl;
            cout << "Storage (in GB) is " << storage << endl;
            cout << "Processor is " << processor << endl;
        }

        void compare(Laptop other) {
            if (storage > other.storage) {
                cout << "this user's laptop has more storage\n";
            }
            else {
                cout << "the other user's laptop has more storage\n";
            }

            if (RAM > other.RAM) {
                cout << "this user's laptop has more RAM\n";
            }
            else {
                cout << "the other user's laptop has more RAM\n";
            }
        }
};

int main () {
    Laptop BilalLaptop ("hp", "10rdf", 8, 256, "intel");
    Laptop AyeshaLaptop ("dell", "Latitude7460", 16, 512, "AMD");

    BilalLaptop.compare(AyeshaLaptop);
}