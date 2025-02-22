//24K-0673
//HATIM MUSTAFA

#include <iostream>
#include <string>
using namespace std;

class Bus;

class Stop {
    public:
    static int stopCount;
    int stopID;
    string name;

    Stop () {}

    Stop (string n) {
        stopID = stopCount++;
        name = n;
    }
};

int Stop::stopCount = 0;

class Student {
    public:
    string name;
    int id;
    bool attendance;
    bool feesPaid;
    Stop pickup;
    Stop dropoff;
    Bus* bus;

    Student (string n, int id, Stop p) {
        name = n;
        this->id = id;
        pickup = p;
        dropoff = Stop("FAST");
        attendance = false;
        feesPaid = false;
        bus = nullptr;
    }

    void PayFees () {
        feesPaid = true;
        cout << "Fees Paid\n";
    }

    void MarkAttendance () {
        if (!feesPaid) {
            cout << "Cannot use transport service because fee not paid\n";
            return;
        }
        if (bus == nullptr) {
            cout << "No Bus assigned\n";
            return;
        }
        attendance = true;
        cout << "Attendance marked\n";
    }

    void registerForBus (Bus* bus);
};

class Bus {
    public:
    int busID;
    Stop* route;
    int numOfStops;

    Bus (int id) {
        busID = id;
        numOfStops = 0;
        route = nullptr;
    }

    ~Bus () {
        delete [] route;
    }

    void addStop (Stop s) {
        Stop* temp = new Stop[numOfStops+1];
        temp[numOfStops] = s;
        for (int i = 0; i < numOfStops; i++) {
            temp[i] = route[i];
        }
        delete [] route;
        route = temp;
        numOfStops++;
        cout << "Stop added\n";
    }
};

void Student::registerForBus (Bus* bus) {
    for (int i = 0; i < bus->numOfStops; i++) {
        if (bus->route[i].stopID == pickup.stopID) {
            this->bus = bus;
            cout << "Bus assigned\n";
            return;
        }
    }
    cout << "This bus does not contain your stop\n";
}

int main () {
    Stop stop1("Dolmen Mall Hyderi");
    Stop stop2("Five star");

    Bus bus1(0);
    Student s1 ("Hatim", 673, stop1);

    s1.registerForBus(&bus1);
    bus1.addStop(stop1);
    bus1.addStop(stop2);

    s1.registerForBus(&bus1);

    s1.MarkAttendance();
    s1.PayFees();
    s1.MarkAttendance();
}