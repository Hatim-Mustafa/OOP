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

        if (quantity > *stock){
            cout << "Quantity is more than stock available!" << endl;
        }
        else{
            *stock -= quantity;
            cout << "Remaining Stock: " << *stock << endl;
        }
    }
};

int main(){
    Book b1;

    b1.update("A Bad Book");

    b1.purchase();

    b1.purchase();
}