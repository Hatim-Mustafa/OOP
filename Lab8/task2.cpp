#include <iostream>
using namespace std;

class Librarian;

class Book {
    private: 
    string title;
    float price;

    public:
    Book (): title("Harry Potter"), price(100) {}

    void display () {
        cout << "title: " << title << endl;
        cout << "price: " << price << endl; 
    }

    friend class Librarian;
};

class Librarian {
    public:
    Librarian () {}

    void applyDiscount(Book& b) {
        b.price *= 0.8;
    }
};

int main () {
    Book b;
    Librarian L;
    b.display();
    L.applyDiscount(b);
    b.display();
}