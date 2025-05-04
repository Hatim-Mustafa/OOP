#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

const string faculty = "faculty";
const string student = "student";
const string bus = "bus";
const string coaster = "coaster";

class Driver;
class Transporter;
class User;
class Student;
class Faculty;
class Vehicle;
class Bus;
class Coaster;
class Seat;
class Route;
class TransportSystem;
class Booking;

class User /*absrtract class*/ {
    public:
    string id;
    string name;
    string email;
    bool hasPaid;
    string userType;
    Vehicle* assignedVehicle;

    User(string id, string name, string email, string userType, bool hp = false)
    : id(id), name(name), email(email), hasPaid(hp), userType(userType), assignedVehicle(nullptr) {}
    virtual void pay() = 0;
    virtual float getFees() = 0;
    virtual ~User () {}
};

class Driver {
    public:
    string id;
    string name;
    string licenseNo;
    Vehicle* assignedVehicle;

    Driver (string id, string name, string l): id(id), name(name), licenseNo(l), assignedVehicle(nullptr) {}

    Driver() {}

    bool assignDriverToVehicle(Transporter& t);
};

class Seat {
    public:
    int seatNo;
    bool isBooked;
    string userType;
    User* BookedBy;

    Seat() {}
    
    Seat(int s, bool b, string ut, User* bb = nullptr): seatNo(s), isBooked(b), userType(ut), BookedBy(bb) {}

    Seat(const Seat& other) {
        seatNo = other.seatNo;
        isBooked = other.isBooked;
        userType = other.userType;
        BookedBy = other.BookedBy;
    }

    void saveToFile(ofstream& out) {
        out << this->seatNo<< endl;
        int n = this->isBooked ? 1 : 0;
        out << n << endl;
        out << this->userType<< endl;
        out << (BookedBy ? BookedBy->id : "null") << endl;
    }
};

class Route {
    public:
    string startPoint;
    string endPoint;
    float distance;
    bool isLongDistance;

    Route() {}

    Route(string s, string e, float f, bool l): startPoint(s), endPoint(e), distance(f), isLongDistance(l) {}

    bool operator == (Route& other) {
        if(startPoint == other.startPoint && endPoint == other.endPoint) {
            return true;
        }
        else {
            return false;
        }
    }

    void saveToFile(ofstream& out) {
        out << this->startPoint<< endl;
        out << this->endPoint<< endl;
        out << this->distance<< endl;
        int n = this->isLongDistance ? 1 : 0;
        out << n << endl;
    }

    void loadFromFile(ifstream& in) {
        string s2, s3;
        getline(in,startPoint);
        getline(in,endPoint);
        getline(in,s2);
        getline(in,s3);
        distance = stof(s2);
        isLongDistance = s3=="1" ? true : false;
    }
};

class Vehicle /*abstract*/{
    public:
    string id;
    bool isAC;
    Driver* driver;
    Route route;
    Seat* seats;
    int numOfSeats;
    Transporter* transporter;
    string vehicleType;

    Vehicle() {}

    Vehicle(string id, bool ac, Driver* d, Route r, Transporter* t, string vt) : id(id), isAC(ac), driver(d), route(r), transporter(t) {
        seats = nullptr;
        numOfSeats = 0;
        vehicleType = vt;
    }

    void operator = (Vehicle& other) {
        id = other.id;
        isAC = other.isAC;
        driver = other.driver;
        route = other.route;
        numOfSeats = other.numOfSeats;
        transporter = other.transporter;
        seats = new Seat[numOfSeats];
        for (int i = 0; i < numOfSeats; i++) {
            seats[i] = other.seats[i];
        }
    }

    virtual bool SeatAvailable(int seatNo, string userType) = 0;

    virtual ~Vehicle () {}

    virtual bool assignVehicleToDriver(Transporter& t) = 0;

    void defineRoute(Route r);
};

class Bus: public Vehicle {
    public:
    Bus (): Vehicle() {}

    Bus(const Vehicle& other) {
        id = other.id;
        isAC = other.isAC;
        driver = other.driver;
        route = other.route;
        numOfSeats = other.numOfSeats;
        transporter = other.transporter;
        seats = new Seat[numOfSeats];
        for (int i = 0; i < numOfSeats; i++) {
            seats[i] = other.seats[i];
        }
    }

    Bus(string id, bool ac, Driver* d, Route r, Transporter* t): Vehicle(id, ac, d, r, t, bus) {
        numOfSeats = 52;
        seats = new Seat[numOfSeats];
        for (int i = 0; i < 10; i++) {
            seats[i] = Seat(i, false, faculty);
        }
        for (int i = 10; i < 52; i++) {
            seats[i] = Seat(i, false, student);
        }
    }

    ~Bus () {
        delete [] seats;
    }

    bool SeatAvailable(int seatNo, string userType) override {
        if (!seats[seatNo].isBooked && userType == seats[seatNo].userType) {
            return true;
        }
        return false;
    }

    bool assignVehicleToDriver(Transporter& t); 

    void defineRoute(Route r) {
        this->route = Route(r.startPoint, r.endPoint, r.distance, r.isLongDistance);
    }
};

class Coaster: public Vehicle {
    public:
    Coaster (): Vehicle() {}

    ~Coaster () {
        delete [] seats;
    }

    Coaster(const Vehicle& other) {
        id = other.id;
        isAC = other.isAC;
        driver = other.driver;
        route = other.route;
        numOfSeats = other.numOfSeats;
        transporter = other.transporter;
        seats = new Seat[numOfSeats];
        for (int i = 0; i < numOfSeats; i++) {
            seats[i] = other.seats[i];
        }
    }

    Coaster(string id, bool ac, Driver* d, Route r, Transporter* t): Vehicle(id, ac, d, r, t, coaster) {
        numOfSeats = 32;
        seats = new Seat[numOfSeats];
        for (int i = 0; i < 6; i++) {
            seats[i] = Seat(i, false, faculty);
        }
        for (int i = 6; i < 32; i++) {
            seats[i] = Seat(i, false, student);
        }
    }

    bool SeatAvailable(int seatNo, string userType) override {
        if (!seats[seatNo].isBooked && userType == seats[seatNo].userType) {
            return true;
        }
        return false;
    }

    bool assignVehicleToDriver(Transporter& t);

    void defineRoute(Route r) {
        this->route = Route(r.startPoint, r.endPoint, r.distance, r.isLongDistance);
    }
};

class Transporter {
    public:
    int id;
    Vehicle** vehicles;
    int numOfVehicles;
    Driver* drivers;
    int numOfDrivers;
    Route* routes;
    int numOfRoutes;

    Transporter (): id(-1), vehicles(nullptr), numOfVehicles(0), drivers(nullptr), numOfDrivers(0), routes(nullptr), numOfRoutes(0) {}

    ~Transporter () {
        delete [] routes;
        delete [] drivers;
        for (int i = 0; i < numOfVehicles; i++) {
            delete vehicles[i];
        }
    }

    void saveToFile(ofstream& out) {
        out << id << endl;
        out << numOfRoutes << endl;
        for (int i = 0; i < numOfRoutes; i++) {
            routes[i].saveToFile(out);
        }

        out << numOfDrivers << endl;
        for (int i = 0; i < numOfDrivers; i++) {
            out << drivers[i].id<< endl;
            out << drivers[i].name<< endl;
            out << drivers[i].licenseNo<< endl;
            out << drivers[i].assignedVehicle->id << endl;
        }

        out << numOfVehicles << endl;
        for (int i = 0; i < numOfVehicles; i++) {
            out << vehicles[i]->vehicleType << endl;
            out << vehicles[i]->id << endl;
            int n = vehicles[i]->isAC ? 1 : 0;
            out << n << endl;
            out << vehicles[i]->driver->id << endl;
            vehicles[i]->route.saveToFile(out);
            out << vehicles[i]->numOfSeats << endl;
            for (int j = 0; j < vehicles[i]->numOfSeats; j++) {
                vehicles[i]->seats[j].saveToFile(out);
            }
        }
    }

    

    void registerRoute(string s, string e, float f, bool l) {
        Route* temp = new Route[numOfRoutes+1];
        temp[numOfRoutes] = Route(s,e,f,l);
        for (int i = 0; i < numOfRoutes; i++) {
            temp[i] = routes[i];
        }
        delete [] routes;
        routes = temp;
        numOfRoutes++;
    }

    void registerDriver(string id, string name, string l) {
        Driver* temp2 = new Driver[numOfDrivers+1];
        temp2[numOfDrivers] = Driver(id, name, l);
        for (int i = 0; i < numOfDrivers; i++) {
            temp2[i] = drivers[i];
        }
        temp2[numOfDrivers].assignDriverToVehicle(*this);
        delete [] drivers;
        drivers = temp2;
        numOfDrivers++;
    }

    void registerVehicle (string id, bool ac, Route r, Transporter* t, string vt) {
        Vehicle** temp1 = new Vehicle*[numOfVehicles+1];
        if(vt == bus) {
            temp1[numOfVehicles] = new Bus(id, ac, nullptr, r, t);
        }
        else {
            temp1[numOfVehicles] = new Coaster(id, ac, nullptr, r, t);
        }
        for (int i = 0; i < numOfVehicles; i++) {
            temp1[i] = vehicles[i];
        }
        temp1[numOfVehicles]->assignVehicleToDriver(*this);
        delete [] vehicles;
        vehicles = temp1;
        numOfVehicles++;
    }

    void loadFromFile(ifstream& in, TransportSystem& t);
};

class Student: public User {
    public:
    Student(string id, string name, string email, bool hp = false): User(id, name, email, student, hp) {}

    void pay() override {
        hasPaid = true;
    }

    float getFees () override {
        float fees = 4000;
        if (assignedVehicle->isAC) {
            fees += 2000;
        }
        return fees;
    }
};

class Faculty: public User {
    public:
    Faculty(string id, string name, string email, bool hp = false): User(id, name, email, faculty, hp) {}
    
    void pay() override {
        hasPaid = true;
    }

    float getFees () override{
        float fees = 3000;
        if (assignedVehicle->isAC) {
            fees += 2000;
        }
        return fees;
    }
};

class Booking {
    public:
    User* user;
    Vehicle* vehicle;
    Seat* seat;
    Route route;
    float fees;
    string date;

    Booking (User* u, Vehicle* v, Seat* s, Route r, float f, string d) : 
    user(u), vehicle(v), seat(s), route(r), fees(f), date(d) {}

    Booking() {}
};

class TransportSystem {
    public:
    User** users;
    Booking* bookings;
    Transporter* transporters;
    int numOfUsers;
    int numOfBookings;
    int numOfTransporters;

    TransportSystem () {
        numOfTransporters = 2;
        transporters = new Transporter[numOfTransporters];
        users = nullptr;
        bookings = nullptr;
        numOfUsers = 0;
        numOfBookings = 0;
    }

    void registerUser(string id, string name, string email, string type) {
        User** temp1 = new User*[numOfUsers+1];
        if(type == student) {
            temp1[numOfUsers] = new Student(id, name, email);
        }
        else {
            temp1[numOfUsers] = new Faculty(id, name, email);
        }
        for (int i = 0; i < numOfUsers; i++) {
            temp1[i] = users[i];
        }
        delete [] users;
        users = temp1;
        numOfUsers++;
    }

    void bookSeat(string userID, string vehicleID, int seatNo, Transporter* t) {
        for (int i = 0; i < numOfUsers; i++) {
            if(users[i]->id == userID) {
                if (!users[i]->hasPaid) {
                    throw "Fees not paid";
                }
                for(int j = 0; j < t->numOfVehicles; j++) {
                    if (t->vehicles[j]->id == vehicleID) {
                        if (t->vehicles[j]->driver == nullptr) {
                            throw "Vehicle has no driver assigned";
                        }
                        if (t->vehicles[j]->SeatAvailable(seatNo, users[i]->userType)) {
                            t->vehicles[j]->seats[seatNo].BookedBy = users[i];
                            t->vehicles[j]->seats[seatNo].isBooked = true;
                            users[i]->assignedVehicle = t->vehicles[j];
                            Booking* temp2 = new Booking[numOfBookings+1];
                            temp2[numOfBookings] = 
                            Booking(users[i], t->vehicles[j], &(t->vehicles[j]->seats[seatNo]), t->vehicles[j]->route, users[i]->getFees(), "today");
                            for (int k = 0; k < numOfBookings; k++) {
                                temp2[k] = bookings[k];
                            }
                            delete [] bookings;
                            bookings = temp2;
                            numOfBookings++;
                        }
                        else {
                            throw "Seat not available";
                        }
                    }
                    else {
                        throw "Vehicle not found";
                    }
                }
            }
            else {
                throw "User not found";
            }
        }

    }

    void saveToFile(ofstream& out) {
        out << numOfUsers << endl;
        for (int i = 0; i < numOfUsers; i++) {
            out << users[i]->userType << endl;
            out << users[i]->id << endl;
            out << users[i]->name << endl;
            out << users[i]->email << endl;
            int n = users[i]->hasPaid ? 1 : 0;
            out << n << endl;
            out << users[i]->assignedVehicle->id << endl;
        }

        out << numOfTransporters << endl;
        for (int i = 0; i < numOfTransporters; i++) {
            transporters[i].saveToFile(out);
        }

        out << numOfBookings << endl;
        for (int i = 0; i < numOfBookings; i++) {
            out << bookings[i].user->id << endl;
            out << bookings[i].vehicle->id << endl;
            out << bookings[i].seat->seatNo << endl;
            bookings[i].route.saveToFile(out);
            out << bookings[i].fees << endl;
            out << bookings[i].date << endl;
        }
    }

    void loadFromFile(ifstream& in) {
        string s;
        string s1, s2, s3, s4, s5;
        int num;
        getline(in, s);
        numOfUsers = stoi(s);
        users = new User*[numOfUsers];
        for (int i = 0 ; i < numOfUsers; i++) {
            getline(in, s);
            if (s == student) {
                getline(in, s);
                getline(in, s1);
                getline(in, s2);
                getline(in, s3);
                getline(in, s4);
                if (s3 == "1") {
                    users[i] = new Student(s, s1, s2, true);
                }
                else {
                    users[i] = new Student(s, s1, s2, false);
                }
            }
            else {
                getline(in, s);
                getline(in, s1);
                getline(in, s2);
                getline(in, s3);
                getline(in, s4);
                if (s3 == "1") {
                    users[i] = new Faculty(s, s1, s2, true);
                }
                else {
                    users[i] = new Faculty(s, s1, s2, false);
                }
            }
        }

        getline(in, s);
        numOfTransporters = stoi(s);
        transporters = new Transporter[numOfTransporters];
        transporters[0].id = 0;
        transporters[1].id = 1;
        for(int i = 0; i < numOfTransporters; i++) {
            transporters[i].loadFromFile(in, *this);
        }

        getline(in, s);
        numOfBookings = stoi(s);
        bookings = new Booking[numOfBookings];
        for (int i = 0; i < numOfBookings; i++) {
            getline(in,s);//user id
            getline(in,s1);//vehicle id
            getline(in,s2);//seat no
            Route r;
            r.loadFromFile(in);
            getline(in,s3);//fees
            getline(in,s4);//date

            User* u;
            Vehicle* v;

            for (int j = 0; j < numOfUsers; j++) {
                if (users[j]->id == s) {
                    u = users[j];
                    break;
                }
            }

            for (int j = 0; j < numOfTransporters; j++) {
                for (int k = 0; k < transporters[j].numOfVehicles; j++) {
                    if (transporters[j].vehicles[k]->id == s1) {
                        v = transporters[j].vehicles[k];
                        break;
                    }
                }
            }

            bookings[i] = Booking(u, v, &(v->seats[stoi(s2)]), r, stof(s3), s4);
        }
    }
};

bool Bus::assignVehicleToDriver(Transporter& t) {
    for (int i = 0; i < t.numOfDrivers; i++) {
        if(t.drivers[i].assignedVehicle == nullptr) {
            this->driver = &(t.drivers[i]);
            t.drivers[i].assignedVehicle = this;
            return true;
        }
    }
    return false;
}

bool Coaster::assignVehicleToDriver(Transporter& t) {
    for (int i = 0; i < t.numOfDrivers; i++) {
        if(t.drivers[i].assignedVehicle == nullptr) {
            this->driver = &(t.drivers[i]);
            t.drivers[i].assignedVehicle = this;
            return true;
        }
    }
    return false;
}

bool Driver::assignDriverToVehicle(Transporter& t) {
    for (int i = 0; i < t.numOfVehicles; i++) {
        if(t.vehicles[i]->driver == nullptr) {
            t.vehicles[i]->driver = this;
            this->assignedVehicle = t.vehicles[i];
            return true;
        }
    }
    return false;
}

void Transporter::loadFromFile(ifstream& in, TransportSystem& t) {
    string s, s1, s2, s3, s4, s5;
    int num;
    getline(in, s);
    numOfRoutes = stoi(s);
    routes = new Route[numOfRoutes];
    for (int i = 0; i < numOfRoutes; i++) {
        routes[i].loadFromFile(in);
    }
    getline(in, s);
    numOfDrivers = stoi(s);
    drivers = new Driver[numOfDrivers];
    for (int i = 0; i < numOfDrivers; i++) {
        getline(in,s);
        getline(in,s1);
        getline(in,s2);
        getline(in,s3);
        drivers[i] = Driver(s, s1, s2);
    }
    getline(in, s);
    numOfVehicles = stoi(s);
    vehicles = new Vehicle*[numOfVehicles];
    for (int i = 0; i < numOfVehicles; i++) {
        getline(in,s);//type
        getline(in,s1);//id
        getline(in,s2);//ac
        getline(in,s3);//driver id
        Route r;
        r.loadFromFile(in);
        getline(in, s4); // transporter id
        getline(in, s5); // seat no

        Driver* d;
        for (int j = 0; j < numOfDrivers; j++) {
            if (drivers[j].id == s3) {
                d = &drivers[j];
                d->assignedVehicle = vehicles[i];
                break;
            }
        }

        if (s == bus) {
            vehicles[i] = new Bus(s1, (s2 == "1" ? true : false), d, r, this);
        }
        else {
            vehicles[i] = new Coaster(s1, (s2 == "1" ? true : false), d, r, this);
        }

        for (int j = 0; j < vehicles[i]->numOfSeats; j++) {
            getline(in,s);
            getline(in,s1);
            getline(in,s2);
            getline(in,s3);
            if (s1 == "1") {
                vehicles[i]->seats[j].isBooked = true;
                for (int k = 0; k < t.numOfUsers; k++) {
                    if (t.users[k]->id == s3) {
                        vehicles[i]->seats[j].BookedBy = t.users[k];
                        t.users[k]->assignedVehicle = vehicles[i];
                    }
                }
            }
        }
    }
}

int main() {
    try {
        TransportSystem t;
        t.transporters[0].id = 0;
        t.transporters[1].id = 1;

        t.transporters[0].registerRoute("Campus", "Downtown", 15.0, false);

        t.transporters[0].registerDriver("D001", "Ali Khan", "LIC1234");

        t.transporters[0].registerVehicle("V001", true, t.transporters[0].routes[0], &t.transporters[0], bus);

        t.registerUser("S001", "Ahmed", "ahmed@example.com", student);

        t.users[0]->pay();

        t.bookSeat("S001", "V001", 30, &t.transporters[0]);

        cout << "Seat booked for student: " << t.users[0]->name << endl;


        ofstream out("transport_data.txt");
        if (!out) throw runtime_error("Failed to open file");
        t.saveToFile(out);
        out.close();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const char*& e) {
        cerr << "Error: " << e << endl;
    }

    return 0;
}