#include <iostream>
#include <exception>
using namespace std;

class InvalidValueException : public exception {
    const char* message;

    public:
    InvalidValueException(const char* m): message(m) {}

    const char* what() const noexcept override {
        return message;
    }
};

int main () {
    int n;
    try {
        cin >> n;
        if (n < 0) {
            throw InvalidValueException("Negative value error");
        }
    }
    catch (InvalidValueException& e) {
        cerr << e.what() << endl;
    }
}