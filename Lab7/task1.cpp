#include <iostream>
using namespace std;

class Account {
    public:
    int accNum;
    float balance;
    string accName;
    string accType;
    float* transactions;
    int numOfTransactions;

    Account (int an, float b, string a, string at): accNum(an), accName(a), balance(b), accType(at) {
        transactions = new float[1];
        transactions[0] = balance;
        numOfTransactions = 1;
    }

    void deposit(float amt) {
        balance+= amt;
        float* temp = new float[numOfTransactions+1];
        temp[numOfTransactions] = amt;
        for (int i = 0; i < numOfTransactions; i++) {
            temp[i] = transactions[i];
        }
        delete [] transactions;
        transactions = temp;
        numOfTransactions++;
    }

    virtual void withdraw(float amt) {
        if (amt < balance) {
            balance-= amt;
            float* temp = new float[numOfTransactions+1];
            temp[numOfTransactions] = -amt;
            for (int i = 0; i < numOfTransactions; i++) {
                temp[i] = transactions[i];
            }
            delete [] transactions;
            transactions = temp;
            numOfTransactions++;
        }
        else {
            cout << "Not enough balance\n";
        }
    }

    virtual float calcInterest () {
        return 0.1*balance;
    }

    void getAccountInfo () {
        cout << "Account Number: " << accNum << endl;
        cout << "Account Name: " << accName << endl;
        cout << "Balance: " << balance << endl;
    }

    void printStatement () {
        for (int i = 0; i < numOfTransactions; i++) {
            if (transactions[i] > 0) {
                cout << "Deposited " << "$" << transactions[i] << endl;;
            }
            else {
                cout << "Withdrawn " << "$" << -transactions[i] << endl;;
            }
        }
    }

    ~Account () {
        delete [] transactions;
    }
};

class CheckingsAccount: public Account {
    public:
    CheckingsAccount(int an, float b, string a): Account(an, b, a, "Checking") {}

};

class SavingsAccount: public Account {
    public:
    float interestRate;
    float minBalance;

    SavingsAccount(int an, float b, string a, float i, float mb): Account(an, b, a, "Savings") {
        interestRate = i;
        minBalance = mb;
    }

    float  calcInterest () override {
        return interestRate*balance;
    }

    void withdraw (float amt) override {
        if (balance - amt < minBalance) {
            cout << "Not enough balance\n";
        }
        else {
            Account::withdraw(amt);
        }
    }

};

class FixedDepositAccount: public Account {
    public:
    string maturityDate;
    float fixedInterestRate;
    FixedDepositAccount(int an, float b, string a): Account(an, b, a, "Fixed Deposit") {}

    float calcInterest () {
        return fixedInterestRate * balance;
    }
};

int main() {
    CheckingsAccount ca (100, 12000, "XYZ");
    SavingsAccount sa (1873, 50000, "ABC", 0.04, 10000);

    ca.deposit(1000);
    ca.withdraw(1200);
    ca.printStatement();

    sa.withdraw(44000);
    
}   