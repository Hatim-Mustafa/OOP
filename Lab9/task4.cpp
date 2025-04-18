#include <iostream>
#include <string>
using namespace std;

class PaymentMethod{
    protected:
    public:
    virtual void processPayment(double amount)=0;
};

class CreditCard:public PaymentMethod{
    private:
    string cardNumber;

    public:
    CreditCard(string cn):cardNumber(cn){}

    void processPayment(double amount)override{
        cout<<"Your amount "<< amount<<" is being processed\n";
    }
};

class DigitalWallet:public PaymentMethod{
    private:
    double balance;

    public:
    DigitalWallet(double b):balance(b){}

    void processPayment(double amount)override{
        if(amount>balance){
            cout<<"balance not enough\n";
        }
        else {
            cout<<"Amount "<<amount<<" deducted from your account\nremaining balance: "<<balance-amount << endl;
            balance-=amount;
        }
    }
};
int main(){
    CreditCard c("1221HJK2112");
    DigitalWallet d(1000.00);
    c.processPayment(50.00);
    d.processPayment(100);
}