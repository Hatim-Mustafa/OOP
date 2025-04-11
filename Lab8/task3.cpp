#include <iostream>
using namespace std;

class Teacher; 

class Student {
private:
    string name;
    int grades[3];

public:
    Student(string n) {
        name = n;
        grades[0] = 91;
        grades[1] = 82;
        grades[2] = 95;
    }

    friend class Teacher;

    friend float calculateAverageGrade(Student& s);
};

class Teacher {
public:
    void viewGrades(Student& s) {
        cout << s.name << "'s Grades: ";
        for (int i = 0; i < 3; ++i) {
            cout << s.grades[i] << " ";
        }
        cout << endl;
    }

    void updateGrade(Student& s, int index, int newGrade) {
        s.grades[index] = newGrade;
    }
};

float calculateAverageGrade(Student& s) {
    float sum = 0;
    for (int i = 0; i < 3; ++i)
        sum += s.grades[i];
    return sum / 3.0f;
}

int main() {
    Student s1("Alice");
    Teacher t1;

    t1.viewGrades(s1);

    cout << "Average: " << calculateAverageGrade(s1) << endl;

    t1.updateGrade(s1, 1, 95);

    cout << "\nAfter grade update:\n";
    t1.viewGrades(s1);
    cout << "New Average: " << calculateAverageGrade(s1) << endl;
}
