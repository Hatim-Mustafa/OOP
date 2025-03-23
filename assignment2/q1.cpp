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

    bool operator==(const Stop& other) const {
        return this->stopID == other.stopID;
    }
};

int Stop::stopCount = 0;

class Passenger {
    public:
    string name;
    int id;
    bool attendance;
    bool feesPaid;
    Stop pickup;
    Stop dropoff;
    Bus* bus;
    int LastFeePaid; //Number of days since last fee paid

    Passenger(string n, int id, Stop p) {
        name = n;
        this->id = id;
        pickup = p;
        dropoff = Stop("FAST");
        attendance = false;
        feesPaid = false;
        bus = nullptr;
        LastFeePaid = 0;
    }

    void PayFees () {
        feesPaid = true;
        cout << "Fees Paid\n";
        LastFeePaid = 0;
    }

    void MarkAttendance () {
        CheckFeeDeadline();
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

    virtual void CheckFeeDeadline () {
        if (LastFeePaid > 1) {
            cout << "Please pay your fees again\n";
            feesPaid = false;
        }
    }

    void registerForBus (Bus* bus);

};

class Student: public Passenger {
    public:
    const int FeesDayLimit = 16*7;

    Student (string n, int id, Stop p): Passenger(n, id, p) {}

    void CheckFeeDeadline () override {
        if (LastFeePaid > FeesDayLimit) {
            cout << "Please pay your fees again\n";
            feesPaid = false;
        }
    }
};

class Teacher: public Passenger {
    public:
    const int FeesDayLimit = 30;

    Teacher(string n, int id, Stop p): Passenger(n, id, p) {}

    void CheckFeeDeadline () override {
        if (LastFeePaid > FeesDayLimit) {
            cout << "Transport Service needs to be renewed, please pay your fees again\n";
            feesPaid = false;
        }
    }
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

void Passenger::registerForBus (Bus* bus) {
    for (int i = 0; i < bus->numOfStops; i++) {
        if (bus->route[i] == pickup) {
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
    Teacher t1 ("Atiya", 123, stop2);

    s1.registerForBus(&bus1);
    bus1.addStop(stop1);
    bus1.addStop(stop2);

    s1.registerForBus(&bus1);
    t1.registerForBus(&bus1);

    s1.MarkAttendance();
    s1.PayFees();
    s1.MarkAttendance();

    t1.PayFees();
    t1.MarkAttendance();
    t1.LastFeePaid = 31;
    t1.MarkAttendance();
}