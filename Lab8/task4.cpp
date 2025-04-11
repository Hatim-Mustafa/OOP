#include <iostream>
using namespace std;

class Currency {
private:
    double amount;

public:
    Currency(double a = 0.0) : amount(a) {}

    Currency operator-() const {
        return Currency(-amount);
    }

    Currency operator+(const Currency& other) const {
        return Currency(amount + other.amount);
    }

    Currency operator-(const Currency& other) const {
        return Currency(amount - other.amount);
    }

    Currency& operator+=(const Currency& other) {
        amount += other.amount;
        return *this;
    }

    Currency& operator-=(const Currency& other) {
        amount -= other.amount;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Currency& c) {
        os << "$" << c.amount;
        return os;
    }
};

int main() {
    Currency price1(50.75);
    Currency price2(19.25);
    Currency discount(5.00);

    Currency total = price1 + price2;
    cout << "Total: " << total << endl;

    Currency afterDiscount = total - discount;
    cout << "After discount: " << afterDiscount << endl;

    Currency negative = -afterDiscount;
    cout << "Negated value: " << negative << endl;

    total += discount;
    cout << "Total after += discount: " << total << endl;

    total -= price2;
    cout << "Total after -= price2: " << total << endl;
}
