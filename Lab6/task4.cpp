#include <iostream>
using namespace std;

class Account {
    public:
    int accNum;
    float balance;

    Account(float b, int a) {
        accNum = a;
        balance = b;
    }

    void displayDetails () {
        cout << "Account Number: " << accNum << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount: public Account {
    public:
    float interestRate;

    SavingsAccount (float b, int a, float i) : Account(b, a), interestRate(i) {}

    void displayDetails () {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class CheckingAccount: public Account {
    public:
    float overDraftLimit;

    CheckingAccount (float b, int a, float o) : Account(b, a), overDraftLimit(o) {}

    void displayDetails () {
        Account::displayDetails();
        cout << "Over Draft Limit: " << overDraftLimit << endl;
    }
};

int main () {
    SavingsAccount saving (120, 12, 0.5);
    CheckingAccount check (1000, 16, 1200);
    saving.displayDetails();
    cout << endl;
    check.displayDetails();
}