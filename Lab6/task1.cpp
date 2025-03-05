#include <iostream>
using namespace std;

class Employee {
    public:
    string name;
    float salary;

    Employee(string n, float s) {
        name = n;
        salary = s;
    }

    void displayDetails () {
        cout << "name: " << name << endl;
        cout << "salary: " << salary << endl;
    }
};

class Manager: public Employee {
    public:
    float bonus;

    Manager (string n, float s, float b) :
        Employee(n, s),
        bonus(b)
    {}

    void displayDetails () {
        Employee::displayDetails();
        cout << "Bonus: " << bonus << endl;
    }
};

int main () {
    Manager man("ahmed", 30, 2);
    man.displayDetails();
}