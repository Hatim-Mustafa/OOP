#include "task3.h"
#include <iostream>
#include <string>
using namespace std;
int main(){
   Book h("Harry Potter", "JK Rowling","AJ5544");
   cout<<"title: "<<h.getTitle()<<"\nauthor: "<<h.getAuthor()<<"\nisbn: "<<h.getISBN()<<endl;
}