#include <iostream>
#include <string>
using namespace std;

class GroceryStore {
    int** cart;
    string* productName;
    int* productStock;
    float* productPrice;
    int productsInCart;
    int productsInInventory;

    public:
    GroceryStore () {
        cart = nullptr;
        productName = nullptr;
        productPrice = nullptr;
        productStock = nullptr;
        productsInCart = 0;
        productsInInventory = 0;
    }

    ~GroceryStore () {
        delete [] productName;
        delete [] productPrice;
        delete [] productStock;
        for (int i = 0; i < productsInCart; i++) {
            delete [] cart[i];
        }
        delete [] cart;
    }

    void AddItemToInventory (string name, int stock, float price) {
        for (int i = 0; i < productsInInventory; i++) {
            if (productName[i] == name) {
                cout << "Item already in inventory\n";
                return;
            }
        }
        int* temp1 = new int[productsInInventory + 1];
        float* temp2 = new float[productsInInventory + 1];
        string* temp3 = new string[productsInInventory + 1];

        temp1[productsInInventory] = stock;
        temp2[productsInInventory] = price;
        temp3[productsInInventory] = name;

        for (int i = 0; i < productsInInventory; i++) {
            temp1[i] = productStock[i];
            temp2[i] = productPrice[i];
            temp3[i] = productName[i];
        }

        delete [] productStock;
        productStock = temp1;
        delete [] productPrice;
        productPrice = temp2;
        delete [] productName;
        productName = temp3;

        productsInInventory++;
        cout << "Item successfully added\n";
    }

    void updatePrice(string name,float price) {
        for (int i = 0; i < productsInInventory; i++) {
            if (productName[i] == name) {
                productPrice[i] = price;
                cout << "Price Updated\n";
                return;
            }
        }
        cout << "Item not present in inventory\n";
    }

    void updateStock(string name,int stock) {
        for (int i = 0; i < productsInInventory; i++) {
            if (productName[i] == name) {
                productStock[i] = stock;
                cout << "Stock Updated\n";
                return;
            }
        }
        cout << "Item not present in inventory\n";
    }

    void AddItemToCart (string name, int amount) {
        for (int i = 0; i < productsInCart; i++) {
            if (productName[cart[i][0]] == name) {
                if (productStock[cart[i][0]] < amount) {
                    cout << "Not enough stock\n";
                    return;
                }
                cart[i][1] += amount;
                cout << "Item successfully added\n";
                return;
            }
        }
        int** temp = new int*[productsInCart + 1];
        for (int i = 0; i < productsInCart+1; i++) {
            temp[i] = new int[2];
        }

        temp[productsInCart][0] = -1;

        for (int i = 0; i < productsInInventory; i++) {
            if (productName[i] == name) {
                temp[productsInCart][0] = i;
                break;
            }
        }

        if (temp[productsInCart][0] == -1) {
            cout << "Item not present in inventory\n";
            for (int i = 0; i < productsInCart; i++) {
                delete [] temp[i];
            }
            delete [] temp;
            return;
        }

        if (productStock[temp[productsInCart][0]] < amount) {
            cout << "Not enough stock\n";
            return;
        }
        temp[productsInCart][1] = amount;

        for (int i = 0; i < productsInCart; i++) {
            temp[i][0] = cart[i][0];
            temp[i][1] = cart[i][1];
            delete [] cart[i];
        }

        delete [] cart;
        cart = temp;

        productsInCart++;

        cout << "Item successfully added\n";
    }

    void DisplayItems () {
        for (int i = 0; i < productsInInventory; i++) {
            cout << "Name: " << productName[i] << "  Price: " << productPrice[i] << "  Stock: " << productStock[i] << endl;
        }
    }

    void DisplayCart () {
        for (int i = 0; i < productsInCart; i++) {
            cout << "Name: " << productName[cart[i][0]] << "  Price: " << productPrice[cart[i][0]] << "  Amount: " << cart[i][1] << endl;
        }
    }

    void generateReceipt () {
        float sum = 0;
        for (int i = 0; i < productsInCart; i++) {
            cout << "Name: " << productName[cart[i][0]] << "  Price: " << productPrice[cart[i][0]] << "  Amount: " << cart[i][1] << endl;
            sum += productPrice[cart[i][0]] * cart[i][1];
            productStock[cart[i][0]] -= cart[i][1];
        }
        cout << "Total sum is " << sum << endl;

        for (int i = 0; i < productsInCart; i++) {
            delete [] cart[i];
        }
        delete [] cart;
        cart = nullptr;
        productsInCart = 0;
    }
};

int main () {
    GroceryStore Store;

    int choice;

    do {
        cout << "\nShop Management:\n";
        cout << "1. Add Item To Inventory\n";
        cout << "2. Update Price\n";
        cout << "3. Update Stock\n";
        cout << "4. Add Item to Cart\n";
        cout << "5. Generate Receipt\n";
        cout << "6. Display Inventory\n";
        cout << "7. Display Cart\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string name; 
        int stock; 
        float price;
        int amount;

        switch (choice) {
            case 1: 
            cout << "Enter name of item: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter price of item: ";
            cin >> price;
            cout << "Enter stock of item: ";
            cin >> stock;

            Store.AddItemToInventory(name, stock, price);
            break;

            case 2:
            cout << "Enter name of item: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new price: ";
            cin >> price;

            Store.updatePrice(name, price); 
            break;

            case 3: 
            cout << "Enter name of item: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new stock: ";
            cin >> stock;

            Store.updateStock(name, stock); 
            break;

            case 4: 
            cout << "Enter name of item: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter amount: ";
            cin >> amount;

            Store.AddItemToCart(name, amount); 
            break;

            case 5: 
            Store.generateReceipt(); 
            break;

            case 6: 
            Store.DisplayItems(); 
            break;

            case 7: 
            Store.DisplayCart(); 
            break;

            case 8:
            cout << "Exiting...\n";
            break;

            default: 
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 8);
}