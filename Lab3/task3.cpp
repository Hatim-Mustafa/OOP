#include <iostream>
using namespace std;

class Planner {
    private:
        string** tasks;
        const string noTask = "No Task";
        const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public:
        Planner () {
            tasks = new string*[12];
            for (int i = 0; i < 12; i++) {
                tasks[i] = new string[months[i]];
            }

            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < months[i]; j++) {
                    tasks[i][j] = noTask;
                }
            }
        }

        ~Planner () {
            for (int i = 0; i < 12; i++) {
                delete [] tasks[i];
            }
            delete [] tasks;
        }

        void add (string task, int month, int day) {
            if (tasks[month-1][day-1] != noTask) {
                cout << "A task already assigned for the day\n";
            }
            else {
                tasks[month-1][day-1] = task;
                cout << "Task successfully assigned\n";
            }
        }

        void remove (int month, int day) {
            tasks[month-1][day-1] = noTask;
            cout << "Task successfull removed\n";
        }

        void display (int month) {
            for (int i = 0; i < months[month-1]; i++) {
                cout << "Task for day " << i+1 << " is " << tasks[month-1][i] << endl;
            }
        }
};

int main () {
    Planner TaskPlanner;

    int choice;

    do {
        cout << "\nTask Manager Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int month; 
        int day; 
        string task;

        switch (choice) {
            case 1: 
            cout << "Enter month: ";
            cin >> month;
            cout << "Enter day: ";
            cin >> day;
            cout << "Enter task: ";
            cin >> task;

            TaskPlanner.add(task, month, day); 
            break;

            case 2:
            cout << "Enter month: ";
            cin >> month;
            cout << "Enter day: ";
            cin >> day;

            TaskPlanner.remove(month, day); 
            break;

            case 3: 
            cout << "Enter month: ";
            cin >> month;

            TaskPlanner.display(month); 
            break;

            case 4: 
            cout << "Exiting...\n"; 
            break;

            default: 
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
}