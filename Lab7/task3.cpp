#include <iostream>
using namespace std;

class Currency {
    float amount;
    int currencyCode;
    string currencySymbol;
    float exchangeRate;

    Currency (float a, int cc, string cs, float er) : amount(a), currencyCode(cc), currencySymbol(cs), exchangeRate(er) {}

    Currency (float a, int cc, string cs) : amount(a), currencyCode(cc), currencySymbol(cs), exchangeRate(0) {}

    float convertToBase () {
        return amount*exchangeRate;
    }

    float convertTo(float er) {
        return amount*exchangeRate/er;
    }

    void displayCurrency () {
        cout << "Curreny Code: " << currencyCode << endl;
        cout << "Currency Symbol: " << currencySymbol << endl;
        cout << "Amount: " << amount << endl;
        if (exchangeRate != 0) {
            cout << "Exchange Rate" << exchangeRate << endl;
        }
    }
};

class Dollar : public Currency {
    
}