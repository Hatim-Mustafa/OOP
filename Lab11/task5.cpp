#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

class InsufficientFundsException : public exception
{
    double deficit;
    string message;

public:
    InsufficientFundsException(double def) : deficit(def)
    {
        stringstream ss;
        ss << "InsufficientFundsException - Deficit: $" << deficit;
        message = ss.str();
    }

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

template <typename T>
class BankAccount
{
    T balance;

public:
    BankAccount(T initialBalance) : balance(initialBalance) {}

    void withdraw(T amount)
    {
        if (amount > balance)
        {
            T deficit = amount - balance;
            throw InsufficientFundsException(deficit);
        }
        balance -= amount;
        cout << "Withdraw successful. Remaining Balance: $" << balance << endl;
    }

    T getBalance() const
    {
        return balance;
    }
};

int main()
{
    BankAccount<double> myAccount(500.00);

    cout << "Balance: $" << myAccount.getBalance() << endl;

    try
    {
        myAccount.withdraw(600.00);
    }
    catch (const InsufficientFundsException &e)
    {
        cout << "Withdraw $600: " << e.what() << endl;
    }

    return 0;
}