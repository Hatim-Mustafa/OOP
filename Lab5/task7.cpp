#include <iostream>
#include <string>
using namespace std;

class Product {
    static int productCount;
    int id;
    string name;
    float price;

    public:
    Product () {};

    Product (string n, float p) : id(productCount++), name(n), price(p) {};

    Product (Product& p) {
        this->id = p.getID();
        this->name = p.getName();
        this->price = p.getPrice();
    }

    void displayDetails () {
        cout << "Product ID: " << id << endl;
        cout << "Product name: " << name << endl;
        cout << "Product price: " << price << endl;
    }

    float getPrice () {
        return price;
    }

    int getID () {
        return id;
    }

    string getName () {
        return name;
    }
};

int Product::productCount = 0;

class Inventory {
    Product** products;
    int numOfProducts;

    public:
    Inventory () {
        products = nullptr;
        numOfProducts = 0;
    }
    Inventory (int n, Product** p) {
        numOfProducts = n;
        products = p;
    }

    ~Inventory () {
        for (int i = 0; i < numOfProducts; i++) {
            delete products[i];
        }
        delete [] products;
    }

    void sort () {
        int n = numOfProducts;
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            Product* temp;
            for (int j = 0; j < n - i - 1; j++) {
                if (products[j]->getPrice() > products[j + 1]->getPrice()) {
                    temp = products[j];
                    products[j] = products[j+1];
                    products[j+1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
        cout << "Products sorted\n";
    }

    void addProduct (Product p) {
        for (int i = 0; i < numOfProducts; i++) {
            if (products[i]->getID() == p.getID()) {
                cout << "Product already in inventory\n";
                return;
            }
        }
        Product** temp1 = new Product*[numOfProducts + 1];

        temp1[numOfProducts] = new Product(p);

        for (int i = 0; i < numOfProducts; i++) {
            temp1[i] = products[i];
        }

        delete [] products;
        products = temp1;

        numOfProducts++;
        cout << "Product successfully added\n";
    }

    Product* search(int id) {
        for (int i = 0; i < numOfProducts; i++) {
            if (products[i]->getID() == id) {
                return products[i];
            }
        }
        cout << "NO product with this ID exists\n";
        return nullptr;
    }

    void displayDetails () {
        cout << "PRODUCTS\n";
        for (int i = 0; i < numOfProducts; i++) {
            products[i]->displayDetails();
            cout << endl;
        }
    }
};

int main () {
    Inventory shop;

    Product prod ("Microwave", 55.99);
    shop.addProduct(prod);
    prod = Product("Bacon", 10);
    shop.addProduct(prod);
    prod = Product("Kurta", 7.49);
    shop.addProduct(prod);
    prod = Product("Eggs", 2.99);
    shop.addProduct(prod);


    shop.displayDetails();
    shop.sort();
    shop.displayDetails();
    Product* p = shop.search(1);
    if (p != nullptr) {
        p->displayDetails();
    }
}