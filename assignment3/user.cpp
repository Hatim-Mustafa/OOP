#include "user.h"
#include <iostream>
using namespace std;

User::User(string id, string name, string email, string userType, bool hp = false)
: id(id), name(name), email(email), hasPaid(hp), userType(userType), assignedVehicle(nullptr) {}

User::~User() {}