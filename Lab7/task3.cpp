#include <iostream>
using namespace std;

class Currency {
    public:
    float amount;
    string currencyCode;
    string currencySymbol;
    float exchangeRate;

    Currency (float a, string cc, string cs, float er) : amount(a), currencyCode(cc), currencySymbol(cs), exchangeRate(er) {}

    Currency (float a, string cc, string cs) : amount(a), currencyCode(cc), currencySymbol(cs), exchangeRate(0) {}

    float convertToBase () {
        return amount*exchangeRate;
    }

    float convertTo(Currency &targetCurrency) {
        return convertToBase()/targetCurrency.exchangeRate;
    }

    virtual void displayCurrency () {
        cout << "Curreny Code: " << currencyCode << endl;
        cout << "Currency Symbol: " << currencySymbol << endl;
        cout << "Amount: " << amount << endl;
        if (exchangeRate != 0) {
            cout << "Exchange Rate" << exchangeRate << endl;
        }
    }
};

class Dollar : public Currency
{
public:
    Dollar(double amt) : Currency(amt, "USD", "USD", 1.0) {} // USD is the base currency (exchange rate = 1)

    void displayCurrency()
    {
        cout << amount << " USD" << endl;
    }
};

class Euro : public Currency
{
public:
    Euro(double amt) : Currency(amt, "EUR", "EUR", 1.1) {} // 1 EUR = 1.1 USD

    void displayCurrency()
    {
        cout << amount << " EUR" << endl;
    }
};

class Rupee : public Currency
{
public:
    Rupee(double amt) : Currency(amt, "PKR", "PKR", 0.0036) {} // 1 PKR = 0.0036 USD

    void displayCurrency()
    {
        cout << amount << " PKR" << endl;
    }
};

int main()
{
    Dollar d(100);
    Euro e(50);
    Rupee r(10000);

    cout << "Initial Currencies:\n";
    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();

    cout << "\nConversions:\n";

    cout << "100 USD to EUR: " << d.convertTo(e) << " EUR\n";
    cout << "50 EUR to USD: " << e.convertTo(d) << " USD\n";
    cout << "10000 PKR to USD: " << r.convertTo(d) << " USD\n";
    cout << "100 USD to PKR: " << d.convertTo(r) << " PKR\n";
}