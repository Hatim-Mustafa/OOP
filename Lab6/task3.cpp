#include <iostream>
using namespace std;

class Person {
    public:
    string name;
    int age;

    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayDetails () {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher: virtual public Person {
    public:
    string subject;

    Teacher(string n, int a, string s): Person(n, a), subject(s) {}

    void displayDetails () {
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
    }
};

class Researcher: virtual public Person {
    public:
    string researchArea;

    Researcher(string n, int a, string s): Person(n, a), researchArea(s) {}

    void displayDetails () {
        Person::displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor: public Teacher, public Researcher {
    public:
    int publications;

    Professor(string n, int a, string s, string r, int p): Person(n,a), Teacher(n, a, s), Researcher(n,a,r), publications(p) {}

    void displayDetails () {
        Teacher::displayDetails();
        cout << "ResearchArea: " << Researcher::researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main () {
    Professor prof("Hamilton", 42, "Psychology", "Brain Psychology", 6);
    prof.displayDetails();
}