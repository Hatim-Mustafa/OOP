#pragma once
#include <iostream>
using namespace std;

class Vehicle;

class User /*absrtract class*/ {
    public:
    string id;
    string name;
    string email;
    bool hasPaid;
    string userType;
    Vehicle* assignedVehicle;

    User(string id, string name, string email, string userType, bool hp = false);
    virtual void pay() = 0;
    virtual float getFees() = 0;
    virtual ~User ();
};