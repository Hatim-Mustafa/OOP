#include <iostream>
#include <string>
using namespace std;

class Book {
    public:
    static int bookCount;
    int id;
    string title;
    float price;
    int *stock;

    Book() : id(bookCount++), title("Unknown"), price(0.0), stock(new int(30)) {}

    Book(string t, float p, int s) : id(bookCount++), title(t), price(p), stock(new int(s)) {}

    Book (Book& obj) : id(bookCount++), title(obj.title), price(obj.price), stock(new int(*obj.stock)) {}

    ~Book () {
        delete stock;
    }

    void update(string title){
        this->title = title;
        cout << "Changed title to " << this->title << endl;
    }
 
    void purchase(){
        int quantity = -1;

        if (*stock <= 5){
            cout << "Low On Stock. Less than 5 books remain" << endl;
        }

        cout << "Enter quantity of books you'd like to purchase of title " << title <<  ": ";
        cin >> quantity;

        float d = applyDiscout(quantity);

        float p = calculatePrice(quantity, d);

        if (quantity > *stock){
            cout << "Quantity is more than stock available!" << endl;
        }
        else{
            *stock -= quantity;
            cout << "Remaining Stock: " << *stock << endl;
            cout << "Total Price: " << p << endl;
        }
    }

    float applyDiscout (int amount) {
        if (amount > 10)  {
            return 0.9;
        }
        else if (amount > 5) {
            return 0.95;
        }
        else {
            return 1;
        }
    }

    float calculatePrice (int quantity, float discount) {
        return (float)quantity * discount * price;
    }

    void displayDetails () {
        cout << "BOOK DETAILS\n";
        cout << "ID: " << this->id << endl;
        cout << "Title: " << this->title << endl;
        cout << "Price: " << this->price << endl;
        cout << "Stock: " << *this->stock << endl;
    }
};

int Book::bookCount = 0;

int main(){
    Book b1("A Good Book", 12, 30);
    b1.displayDetails();
    b1.purchase();
    Book b2(b1);
    b2.price = 15;
    b2.displayDetails();
}