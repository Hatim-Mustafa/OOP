#include <iostream>
#include <string>
using namespace std;

class Book {
    public:
    string title;
    float price;
    int *stock;

    Book() {
        title = "Unknown";
        price = 0.0;
        stock = new int(30);
    }

    Book(string t, float p, int s) {
        title = t;
        price = p;
        stock = new int(s);
    }

    Book (Book& obj) {
        this->title = obj.title;
        this->price = obj.price;
        this->stock = new int(*obj.stock);
    }

    ~Book () {
        delete stock;
    }

    void update(string s){
        title = s;
        cout << "Changed title to " << title << endl;
    }
 
    void purchase(){
        int quantity = -1;

        if (*stock <= 5){
            cout << "Low On Stock. Less than 5 books remain" << endl;
        }

        cout << "Enter quantity of books you'd like to purchase of title " << title <<  ": ";
        cin >> quantity;

        float p = applyDiscout(quantity);

        if (quantity > *stock){
            cout << "Quantity is more than stock available!" << endl;
        }
        else{
            *stock -= quantity;
            cout << "Remaining Stock: " << *stock << endl;
            cout << "Total Price: " << p * quantity << endl;
        }
    }

    float applyDiscout (int amount) {
        if (amount > 10)  {
            return (float)price * 0.9;
        }
        else if (amount > 5) {
            return (float)price * 0.95;
        }
        else {
            return price;
        }
    }
};

int main(){
    Book b1("A Good Book", 12, 30);

    Book b2(b1);

    b1.update("A Bad Book");

    cout << b1.title << endl;
    cout << b2.title << endl;

    *b2.stock = 10;
    cout << *b1.stock << endl;
    cout << *b2.stock << endl;
}