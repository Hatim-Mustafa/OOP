#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <typeinfo>
#include <exception>
using namespace std;

class NegativeNumberException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "NegativeNumberException - Input must be non-negative!";
    }
};

class InvalidTypeException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "InvalidTypeException - Non-numeric type detected!";
    }
};

template <typename T>
double sqrtm(T num)
{ // all other types get rejecte here. generic block
    throw InvalidTypeException();
}

template <>
double sqrtm<int>(int num)
{
    if (num < 0)
        throw NegativeNumberException();
    return sqrt(num);
}

template <>
double sqrtm<double>(double num)
{
    if (num < 0)
        throw NegativeNumberException();
    return sqrt(num);
}

int main()
{
    try
    {
        cout << "sqrt(25): " << sqrtm(25) << endl;
        cout << "sqrt(-4): " << sqrtm(-4) << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    try
    {
        cout << "sqrt(\"hello\"): " << sqrtm(string("hello")) << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}