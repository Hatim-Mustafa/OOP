//24K-0673
//HATIM MUSTAFA

#include <iostream>
#include <string>
using namespace std;

const int prof = 177685;
const int stud = 177688;
const int ta = 177689;

int Hash(char c) {
    return (5381* 33) + c;
}

class Student;
class TA;
class Professor;

class User {
    public:
    string name;
    int id;
    string email;
    string* permissions;
    int numOfPermissions;

    protected:
    int hashedPassword;

    public:
    User(string n, int id, string e, string password, string* p, int np):
    name(n), id(id), email(e), hashedPassword(Hash(password[0])), numOfPermissions(np) {
        permissions = new string[numOfPermissions];
        for (int i = 0; i < numOfPermissions; i++) {
            permissions[i] = p[i];
        }
    }

    User () {}

    virtual ~User () {
        delete [] permissions;
    }

    string authenticate () {
        if (hashedPassword == prof) {
            return "PROFESSOR";
        }
        else if (hashedPassword == stud) {
            return "STUDENT";
        }
        else if (hashedPassword == ta) {
            return "TEACHER ASSISTANT";
        }
        else {
            return "WP";
        }
    }

    virtual void display () {
        string role = authenticate();
        if (role == "WP") {
            cout << "Invalid Password\n";
            return;
        }
        cout << role << endl;
        cout << "Name: " << name << "\nID: " << id << "\nEmail: " << email << "\nPermissions:\n";
        for (int i = 0; i < numOfPermissions; i++) {
            cout << permissions[i] << endl;
        }
    }

    void labAccess () {
        string role = authenticate();
        if (role == "PROFESSOR") {
            cout << "Full Lab Access granted\n";
        }
        else if (role == "TEACHER ASSISTANT") {
            cout << "Lab Assistance Access granted\n";
        }
        else if (role == "STUDENT") {
            cout << "Lab Access denied\n";
        }
        else {
            cout << "Role not clear, lab access denied\n";
        }
    }

    virtual void submitAssignment (int index) {}
    virtual void viewProjects () {}
};

class Student : public User {
    protected:
    int* assignments;
    int numOfAssignemnts;

    public:
    Student(string n, int id, string e, string password, string* p, int np, int na): 
    User(n,id,e,password,p,np), numOfAssignemnts(na) {
        assignments = new int[na];
        for (int i = 0 ; i< na; i++) {
            assignments[i] = 0;
        }
    }

    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] assignments;
            delete[] permissions;

            name = other.name;
            id = other.id;
            email = other.email;
            hashedPassword = other.hashedPassword;
            numOfPermissions = other.numOfPermissions;
            numOfAssignemnts = other.numOfAssignemnts;
            permissions = new string[numOfPermissions];
            for (int i = 0; i < numOfPermissions; i++) {
                permissions[i] = other.permissions[i];
            }
    
            assignments = new int[numOfAssignemnts];
            for (int i = 0; i < numOfAssignemnts; i++) {
                assignments[i] = other.assignments[i];
            }
        }
        return *this;
    }

    Student () {
        assignments = nullptr;
        permissions = nullptr;
        numOfAssignemnts = 0;
        numOfPermissions = 0;
    }

    ~Student () {
        delete [] assignments;
    }

    void display () override {
        User::display();

        cout << "ASSIGNMENTS\n";
        for (int i = 0 ; i < numOfAssignemnts; i++) {
            cout << "Assignment " << i+1 << ": ";
            if (assignments[i] == 0) {
                cout << "Incomplete\n";
            }
            else {
                cout << "Complete\n";
            }
        }
    }

    void giveAssignment () {
        int* temp = new int[numOfAssignemnts+1];
        temp[numOfAssignemnts] = 0;
        for (int i = 0; i < numOfAssignemnts; i++) {
            temp[i] = assignments[i];
        }
        delete [] assignments;
        assignments = temp;
        numOfAssignemnts++;
        cout << "assignment given\n";
    }

    void submitAssignment (int index) {
        if (index > numOfAssignemnts) {
            cout << "Incorrect assignment number\n";
            return;
        }
        assignments[index-1] = 1;
        cout << "assignment " << index << " submitted\n";
    }
};

class TA : public Student {
    private:
    Student assignedStudents[10];
    const int maxStudents = 10;
    int numOfStudents;
    int numOfProjects;
    const int maxProjects = 2;
    string projects[2];

    public:
    TA (string n, int id, string e, string password, string* p, int np, int na) : Student(n, id, e, password, p, np, na) {
        numOfStudents = 0;
        numOfProjects = 0;
    }

    void display () override {
        Student::display();
        viewProjects();
        cout << "ASSIGNED STUDENTS\n";
        if (numOfStudents == 0) {
            cout << "No Students\n";
        }
        for (int i = 0; i < numOfStudents; i++) {
            cout << assignedStudents[i].name << endl;
        }
    }

    void addProject (string p) {
        if (numOfProjects == maxProjects) {
            cout << "Cannot add more projects\n";
            return;
        }
        projects[numOfProjects] = p;
        numOfProjects++;
        cout << "project added\n";
    }

    void removeProject (string p) {
        int index;
        for (int i = 0; i < numOfProjects; i++) {
            if (projects[i] == p) {
                index = i;
                break;
            }
        }
        for (int i = index; i < maxProjects-1; i++) {
            projects[i] = projects[i+1];
        }
        numOfProjects--;
        cout << "project removed\n";
    }

    void viewProjects () {
        cout << "PROJECTS\n";
        if (numOfProjects == 0) {
            cout << "No Projects\n";
            return;
        }
        for (int i = 0; i < numOfProjects; i++) {
            cout << projects[i] << endl;
        }
    }

    void addStudent (Student& s) {
        if (numOfStudents == maxStudents) {
            cout << "Cannot add more studentss\n";
            return;
        }
        assignedStudents[numOfStudents] = s;
        numOfStudents++;
        cout << "student added\n";
    }

    void removeStudent (int id) {
        int index;
        for (int i = 0; i < numOfStudents; i++) {
            if (assignedStudents[i].id == id) {
                index = i;
                break;
            }
        }
        for (int i = index; i < maxStudents-1; i++) {
            assignedStudents[i] = assignedStudents[i+1];
        }
        numOfStudents--;
        cout << "student removed\n";
    }
};

class Professor : public User {
    public:
    Professor (string n, int id, string e, string password, string* p, int np) : User(n, id, e, password, p, np) {}

    void assignProject (string p, TA& ta) {
        ta.addProject(p);
    }

    void display () override {
        User::display();
    }
};

void authenticateAndPerformAction (User* user, string action) {
    string identity = user->authenticate();
    if (identity == "STUDENT") {
        if (action == "submit assignment") {
            int num;
            cout << "Enter assignment number: ";
            cin >> num;
            user->submitAssignment(num);
        }
        else {
            cout << "Action cannot be performed\n";
        }
    }
    else if (identity == "TEACHER ASSISTANT") {
        if (action == "view projects") {
            user->viewProjects();
        }
        else if (action == "manage_students") {
            cout<<"Managing Students\n";
        }
        else if (action == "assist_labs") {
            user->labAccess();
        }
        else {
            cout << "Action cannot be performed\n";
        }
    }
    else if (identity == "PROFESSOR") {
        if (action == "full_lab_access") {
            user->labAccess();
        }
        else if (action == "assign projects") {
            cout << "Assigning projects\n";
        }
        else {
            cout << "Action cannot be performed\n";
        }
    }
}

int main () {
    string stud_permissions[] = {"submit assignment"};
    string ta_permissions[] = {"view projects", "manage_students", "assist_labs"};
    string prof_permissions[] = {"full_lab_access", "assign projects"};

    Professor prof1 ("Albert", 102, "abc@gamil.com", "professor", prof_permissions, 2);
    Student s1 ("Amna", 1240, "pqr@gmail.com", "student", stud_permissions, 1, 2);
    TA ta1 ("Alfred", 1310, "xyz@gmail.com", "ta", ta_permissions, 3, 4);

    authenticateAndPerformAction(&prof1, "full_lab_access");
    cout <<"-------------------------------------------------\n";
    authenticateAndPerformAction(&s1, "submit assignment");
    cout <<"-------------------------------------------------\n";
    s1.giveAssignment();
    cout <<"-------------------------------------------------\n";
    ta1.addStudent(s1);
    cout <<"-------------------------------------------------\n";
    prof1.assignProject("Tetris Game", ta1);
    cout <<"-------------------------------------------------\n";
    ta1.display();
    cout <<"-------------------------------------------------\n";
    s1.display();
    cout <<"-------------------------------------------------\n";
    prof1.display();
}