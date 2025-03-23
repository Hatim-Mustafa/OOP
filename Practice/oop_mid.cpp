#include <iostream>
using namespace std;

class Employee {
    private:
    static int nextEmployeeID;

    public:
    int employeeID;
    string name;
    float salary;
    const float MAX_SALARY = 1000;

    Employee (string n, float s) {
        setSalary(s);
        name = n;
        employeeID = nextEmployeeID;
    }

    void setSalary(float s) {
        if (s > MAX_SALARY) {
            salary = MAX_SALARY;
        }
        else {
            salary = s;
        }
    }

    void displayInfo () {
        cout << name << endl;
        cout << employeeID << endl;
        cout << salary << endl;
    }

    static void generateEmployeeID () {
        nextEmployeeID++;
    }
};

int Employee::nextEmployeeID = 0;

int main () {
    Employee::generateEmployeeID();
    Employee e1("Nathan", 100);
    e1.hello();
    Employee::generateEmployeeID();
    Employee e2("Albert", 500);

    e1.displayInfo();
}