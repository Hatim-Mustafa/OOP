//24K-0673
//HATIM MUSTAFA

#include <iostream>
#include <string>
using namespace std;

class Student;
class Mentor;
class Sport;
class Skill;

class Skill {
    public:
    int skillID;
    string name;
    string description;

    public:
    Skill(int id, string name, string desc) {
        skillID = id;
        this->name = name;
        description = desc;
    }

    Skill () {
        skillID = -1;
        name = "";
        description = "";
    }

    void showSkillDetails() {
        cout << "Skill ID: " << skillID << endl;
        cout << "Skill name: " << name <<  endl;
        cout << "Skill description: " << description << endl;
    }

    void updateSkillDescription(string newDescription) {
        description = newDescription;
    }
};

class Sport {
    public:
    int sportID;
    string name;
    string description;
    Skill* requiredSkills;
    int numOfSkills;

    public:
    Sport (int id, string name, string desc) {
        sportID = id;
        this->name = name;
        description = desc;
        numOfSkills = 0;
        requiredSkills = nullptr;
    }

    Sport () {
        sportID = -1;
        name = "";
        description = "";
        numOfSkills = 0;
        requiredSkills = nullptr;
    }

    ~Sport () {
        delete [] requiredSkills;
    }

    void addSkill(Skill s) {
        Skill* temp = new Skill[numOfSkills+1];
        temp[numOfSkills] = s;
        for (int i = 0; i < numOfSkills; i++) {
            temp[i] = requiredSkills[i];
        }
        delete [] requiredSkills;
        requiredSkills = temp;
        numOfSkills++;
        cout << "Skill added\n";
    }

    void removeSkill(Skill s) {
        int index = -1;
        for (int i = 0; i < numOfSkills; i++) {
            if (requiredSkills[i].skillID == s.skillID) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Skill is not in the list\n";
            return;
        }

        Skill* temp = new Skill[numOfSkills-1];
        for (int i = 0; i < index; i++) {
            temp[i] = requiredSkills[i];
        }
        for (int i = index+1; i < numOfSkills; i++) {
            temp[i-1] = requiredSkills[i];
        }
        delete [] requiredSkills;
        requiredSkills = temp;
        numOfSkills--;
        cout << "Skill removed\n";
    }
};

class Student {
    public:
    int studentID;
    string name;
    int age;
    Sport* sportsInterests;
    Mentor* mentorAssigned;
    int numOfSportInterests;

    public:
    Student (int id, string n, int age) {
        studentID = id;
        name = n;
        this->age = age;
        sportsInterests = nullptr;
        numOfSportInterests = 0;
        mentorAssigned = nullptr;
    }

    Student () {
        studentID = -1;
        name = "";
        age = -1;
        sportsInterests = nullptr;
        numOfSportInterests = 0;
        mentorAssigned = nullptr;
    }

    ~Student () {
        delete [] sportsInterests;
    }

    void registerForMentorship (Mentor* m);

    void viewMentorDetails();

    void updateSportsInterest (Sport s) {
        Sport* temp = new Sport[numOfSportInterests+1];
        temp[numOfSportInterests] = s;
        for (int i = 0; i < numOfSportInterests; i++) {
            temp[i] = sportsInterests[i];
        }
        delete [] sportsInterests;
        sportsInterests = temp;
        numOfSportInterests++;
        cout << "Sport added\n";
    }

    void displayDetails () {
        cout << "Student ID is: " << studentID << endl;
        cout << "Student name is: " << name << endl;
        cout << "Student age is: " << age << endl;
    }
};

class Mentor {
    public:
    int mentorID;
    string name;
    Sport* sportsExpertise;
    int MaxLearners;
    Student* AssignedLearners;
    int numOfAssignedLearners;

    public:
    Mentor (int id, string name, int m, Sport* s){
        mentorID = id;
        this->name = name;
        MaxLearners = m;
        AssignedLearners = nullptr;
        numOfAssignedLearners = 0;
        sportsExpertise = s;
    }

    Mentor () {
        mentorID = -1;
        name = "";
        AssignedLearners = nullptr;
        numOfAssignedLearners = 0;
        MaxLearners = 0;
    }

    ~Mentor () {
        delete [] sportsExpertise;
        delete [] AssignedLearners;
    }

    void displayDetails () {
        cout << "Mentor ID is: " << mentorID << endl;
        cout << "Mentor name is: " << name << endl;
    }

    Mentor* assignLearner(Student s) {
        if (numOfAssignedLearners == MaxLearners) {
            cout << "Max amount of learners already assigned\n";
            return nullptr;
        }

        Student* temp = new Student[numOfAssignedLearners+1];
        temp[numOfAssignedLearners] = s;
        for (int i = 0; i < numOfAssignedLearners; i++) {
            temp[i] = AssignedLearners[i];
        }
        delete [] AssignedLearners;
        AssignedLearners = temp;
        numOfAssignedLearners++;
        cout << "Student added\n";
        return this;
    }

    void removeLearner(Student s) {
        int index = -1;
        for (int i = 0; i < numOfAssignedLearners; i++) {
            if (AssignedLearners[i].studentID == s.studentID) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Student is not in the list\n";
            return;
        }

        Student* temp = new Student[numOfAssignedLearners-1];
        for (int i = 0; i < index; i++) {
            temp[i] = AssignedLearners[i];
        }
        for (int i = index+1; i < numOfAssignedLearners; i++) {
            temp[i-1] = AssignedLearners[i];
        }
        delete [] AssignedLearners;
        AssignedLearners = temp;
        numOfAssignedLearners--;
        cout << "Student removed\n";
    }

    void provideGuidance() {
        cout << "Providing Guidance\n";
    }

    void viewLearners() {
        for (int i = 0; i < numOfAssignedLearners; i++) {
            cout << "Student " << i+1 << endl;
            AssignedLearners[i].displayDetails();
            cout << endl;
        }
    }
};

void Student::registerForMentorship (Mentor* m) {
    mentorAssigned = m->assignLearner(*this);
}

void Student::viewMentorDetails () {
    if (mentorAssigned == nullptr) {
        cout << "No mentor assigned\n";
        return;
    }
    mentorAssigned->displayDetails();
}

int main () {

}

