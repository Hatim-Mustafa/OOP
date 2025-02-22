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

    Skill () {}

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

    Sport (const Sport& other) {
        sportID = other.sportID;
        name = other.name;
        description = other.description;
        numOfSkills = other.numOfSkills;

        if (other.requiredSkills != nullptr) {
            requiredSkills = new Skill[numOfSkills];
            for (int i = 0; i < numOfSkills; i++) {
                requiredSkills[i] = other.requiredSkills[i];
            }
        } else {
            requiredSkills = nullptr;
        }
    }

    Sport () {
        requiredSkills = nullptr;
    }

    ~Sport () {
        if (requiredSkills != nullptr) {
            delete [] requiredSkills;
            requiredSkills = nullptr;
        }
    }

    Sport& operator=(const Sport& other) {
        if (this != &other) { 
            delete[] requiredSkills; 
            sportID = other.sportID;
            name = other.name;
            description = other.description;
            numOfSkills = other.numOfSkills;
            
            if (other.requiredSkills) {
                requiredSkills = new Skill[numOfSkills];
                for (int i = 0; i < numOfSkills; i++) {
                    requiredSkills[i] = other.requiredSkills[i];
                }
            } else {
                requiredSkills = nullptr;
            }
        }
        return *this;
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

    Student(const Student& other) {
        studentID = other.studentID;
        name = other.name;
        age = other.age;
        numOfSportInterests = other.numOfSportInterests;

        if (other.sportsInterests) {
            sportsInterests = new Sport[numOfSportInterests];
            for (int i = 0; i < numOfSportInterests; i++) {
                sportsInterests[i] = other.sportsInterests[i];
            }
        } else {
            sportsInterests = nullptr;
        }

        mentorAssigned = other.mentorAssigned;
    }

    Student () {
        sportsInterests = nullptr;
    }

    ~Student () {
        if (sportsInterests != nullptr) {
            delete [] sportsInterests;
            sportsInterests = nullptr;
        }
    }

    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] sportsInterests;
            
            studentID = other.studentID;
            name = other.name;
            age = other.age;
            numOfSportInterests = other.numOfSportInterests;
            
            if (other.sportsInterests) {
                sportsInterests = new Sport[numOfSportInterests];
                for (int i = 0; i < numOfSportInterests; i++) {
                    sportsInterests[i] = other.sportsInterests[i];
                }
            } else {
                sportsInterests = nullptr;
            }

            mentorAssigned = other.mentorAssigned;
        }
        return *this;  
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
        cout << s.name << " Sport added\n";
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
    int numOfSportExpertise;
    int MaxLearners;
    Student* AssignedLearners;
    int numOfAssignedLearners;

    public:
    Mentor (int id, string name, int m, Sport* s, int n){
        mentorID = id;
        this->name = name;
        MaxLearners = m;
        AssignedLearners = nullptr;
        numOfAssignedLearners = 0;
        numOfSportExpertise = n;
        sportsExpertise = new Sport[n];
        for (int i = 0; i < n; i++) {
            sportsExpertise[i] = s[i];
        }
    }

    Mentor(const Mentor& other) {
        mentorID = other.mentorID;
        name = other.name;
        MaxLearners = other.MaxLearners;
        numOfAssignedLearners = other.numOfAssignedLearners;
        numOfSportExpertise = other.numOfSportExpertise;
    
        sportsExpertise = new Sport[numOfSportExpertise];
        for (int i = 0; i < numOfSportExpertise; i++) {
            sportsExpertise[i] = Sport(other.sportsExpertise[i]);
        }
        AssignedLearners = new Student[numOfAssignedLearners];
        for (int i = 0; i < numOfAssignedLearners; i++) {
            AssignedLearners[i] = other.AssignedLearners[i];
        }
    }

    Mentor () {
        AssignedLearners = nullptr;
    }

    ~Mentor () {
        delete [] sportsExpertise;
        sportsExpertise = nullptr;
        delete [] AssignedLearners;
        AssignedLearners = nullptr;
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

        if (numOfAssignedLearners - 1 == 0) {
            delete [] AssignedLearners;
            AssignedLearners = nullptr;
            numOfAssignedLearners = 0;
            cout << "Student removed\n";
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
    Skill skill1 (0, "Catching", "Be able to catch a ball");
    Skill skill2 (1, "Kicking", "Precisely Kicking the ball");
    Skill skill3 (2, "Hand Eye Coordination", "Eyes and hands both focused at a single point");
    Skill skill4 (3, "Quick Reflexes", "Being able to react and move at a fast pace");

    Sport sport1 (0, "Cricket", "Sport about a bat and ball");
    sport1.addSkill(skill1);
    sport1.addSkill(skill3);
    sport1.addSkill(skill4);

    Sport sport2 (1, "Football", "Sport about kicking a ball into a goal");
    sport1.addSkill(skill2);
    sport1.addSkill(skill4);

    Sport sport3 (2, "Badminton", "Sport about hitting a shuttlecock with a racket");
    sport1.addSkill(skill3);
    sport1.addSkill(skill4);

    Student student1 (0, "Hatim", 19);
    student1.updateSportsInterest(sport1);
    student1.updateSportsInterest(sport3);

    Student student2 (1, "Robert", 18);
    student2.updateSportsInterest(sport1);
    student2.updateSportsInterest(sport2);
    
    Sport s[] = {sport2};
    Mentor mentor1 (0, "Hamid", 5, s, 1);
    
    Sport s1[] = {sport1, sport3};
    Mentor mentor2 (1, "Jawed", 4, s1, 2);

    student1.registerForMentorship(&mentor2);

    student2.registerForMentorship(&mentor1);

    mentor1.provideGuidance();
    mentor2.provideGuidance();

    mentor1.removeLearner(student2);
}