#include <iostream>
#include <exception>
using namespace std;

class StackOverflowException : public exception {

    public:
    StackOverflowException() {}

    const char* what() const noexcept override {
        return "Stack full";
    }
};

class StackUnderflowException : public exception {

    public:
    StackUnderflowException() {}

    const char* what() const noexcept override {
        return "Stack empty";
    }
};

template <typename T>
class Stack {
private:
    static const int MAX = 10;
    T arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(T val) {
        if (isFull()) {
            throw StackOverflowException();
        }
        arr[++top] = val;
    }

    void pop() {
        if (isEmpty()) {
            throw StackUnderflowException();
        }
        top--;
    }
};

int main() {
    Stack<int> s;

    try {
        s.pop();
    }
    catch (StackUnderflowException& e) {
        cerr << e.what() << endl;
    }
    
    s.push(10);
    s.push(20);
    s.push(30);

    return 0;
}
