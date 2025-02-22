//24K-0673
//HATIM MUSTAFA

#include <iostream>
#include <string>
using namespace std;

class User {
    public:
    string name;
    int age;
    int licenseType; // 1 for Learner, 2 for Intermediate, 3 for Full
    int id;
    static int userCount;
    string contactInfo;

    public:
    User () {}

    User (int age, string n, int lt, string contact) {
        id = userCount++;
        this->age = age;
        name = n;
        licenseType = lt;
        contactInfo = contact;
    }



};

int User::userCount = 0;

class Vehicle {
    public:
    int model;
    int eligibility;
    float rentalPerDay;

    Vehicle () {}

    Vehicle (int m, int e, float r) {
        model = m;
        eligibility = e;
        rentalPerDay = r;
    }

    bool CheckEligibility (User user) {
        if (user.licenseType >= eligibility) {
            return true;
        }
        else {
            return false;
        }
    }

    void displayDetails () {
        cout << "Model: " << model << endl;
        cout << "License Eligibility: " << eligibility << endl;
        cout << "Rental Price Per Day: " << rentalPerDay << endl;
    }
};

void addVehicle (Vehicle*& v, int& n) {
    int m, e;
    float r;
    cout << "Enter model: ";
    cin >> m;
    cout << "Enter license eligibility: ";
    cin >> e;
    cout << "Enter rental price per day: ";
    cin >> r;
    Vehicle* temp = new Vehicle[n+1];
    for (int i = 0; i < n; i++) {
        temp[i] = v[i];
    } 
    temp[n] = Vehicle(m, e, r);
    delete [] v;
    v = temp;
    n++;
}

void addUser (User*& v, int& n) {
    string name, contact;
    int age, license;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter contact info: ";
    cin >> contact;
    cout << "Enter License Type (1 for Learner, 2 for Intermediate, 3 for Full): ";
    cin >> license;
    User* temp = new User[n+1];
    for (int i = 0; i < n; i++) {
        temp[i] = v[i];
    } 
    temp[n] = User(age, name, license, contact);
    delete [] v;
    v = temp;
    n++;
}

int main () {
    int numOfVehicles = 0;
    int numOfUsers = 0;
    Vehicle* vehicles = nullptr;
    User* users = nullptr;

    int choice;
    int id, n, days;
    string name, contact;
    int age, license;

    do {
        cout << "1) Register User\n";
        cout << "2) Change name\n";
        cout << "3) Change License Type\n";
        cout << "4) Change Contact Info\n";
        cout << "5) Change Age\n";
        cout << "6) Add Vehicle\n";
        cout << "7) Rent a vehicle\n";
        cout << "8) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
            addUser(users, numOfUsers);
            break;

            case 2:
            cout << "Enter user id: ";
            cin >> id;
            if (id >= numOfUsers) {
                cout << "User doesnt exist\n";
                break;
            }
            cout << "Enter name: ";
            cin >> name;
            users[id].name = name;
            break;

            case 3:
            cout << "Enter user id: ";
            cin >> id;
            if (id >= numOfUsers) {
                cout << "User doesnt exist\n";
                break;
            }
            cout << "Enter License Type (1 for Learner, 2 for Intermediate, 3 for Full): ";
            cin >> license;
            users[id].licenseType = license;
            break;

            case 4:
            cout << "Enter user id: ";
            cin >> id;
            if (id >= numOfUsers) {
                cout << "User doesnt exist\n";
                break;
            }
            cout << "Enter Contact Info: ";
            cin >> contact;
            users[id].contactInfo = contact;
            break;

            case 5:
            cout << "Enter user id: ";
            cin >> id;
            if (id >= numOfUsers) {
                cout << "User doesnt exist\n";
                break;
            }
            cout << "Enter age: ";
            cin >> age;
            users[id].age = age;
            break;

            case 6:
            addVehicle(vehicles, numOfVehicles);
            break;

            case 7:
            for (int i = 0; i < numOfVehicles; i++) {
                cout << i+1 << endl;
                vehicles[i].displayDetails();
                cout << endl;
            }
            cout << "Enter number of vehicle: ";
            cin >> n;
            if (n > numOfVehicles) {
                cout << "Vehicle does not exist\n";
                break;
            }
            cout << "Enter user id: ";
            cin >> id;
            if (id >= numOfUsers) {
                cout << "User doesnt exist\n";
                break;
            }
            if (vehicles[n-1].CheckEligibility(users[id])) {
                cout << "How many days do you want to rent for: ";
                cin >> days;
                cout << "Your rent will be " << days*vehicles[n-1].rentalPerDay << endl;
            } 
            else {
                cout << "User not eligible for renting this vehicle\n";
            }
            break;

            case 8:
            cout << "Exiting...\n";
            break;

            default:
            cout << "Incorrect Choice\n";
        }
    } while (choice!= 8);
    delete [] vehicles;
    delete [] users;
}