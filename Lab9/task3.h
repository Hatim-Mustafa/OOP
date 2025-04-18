#ifndef BOOK
#define BOOK
#include <string>
using namespace std;
class Book{
   protected:
   string title,isbn,author;
   public:
   Book(string n="",string a="",string i=""):title(n),isbn(i),author(a){}
   string getTitle(){return title;}
   string getISBN(){return isbn;}
   string getAuthor(){return author;}
   
};
#endif