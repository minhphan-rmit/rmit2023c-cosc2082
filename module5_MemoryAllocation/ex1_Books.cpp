#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::string;  

class Book {
private:
  string name;
  int price;

public:
  // constructor
  Book(string nameVal = "", int priceVal = 0)
      : name(nameVal), price(priceVal) {}

  // function to return info as a string
  string toString() {
    std::stringstream sstr;
    sstr << "name: " << name << ", price: " << price;
    return sstr.str(); // get and return string content from the stringstream
  }

  // Extra get and set functions to access private attributes
  void setName(string nameVal) { name = nameVal; }
  void setPrice(int priceVal) { price = priceVal; }

  int getPrice() { return price; }
};

int main() {
  // Qa
  // request dynamic memory allocation
  Book *book1 = new (std::nothrow) Book("Harry Potter", 100);
  Book *book2 = new (std::nothrow) Book("Doremon", 200);
  Book *book3 = new (std::nothrow) Book("Dragon Balls", 300);

  if (book1 == nullptr || book2 == nullptr || book3 == nullptr) {
    cout << "Fail to request memory allocation for book objects \n";
    return -1;
  }

  // print out info using range based for loop
  for (Book *book : {book1, book2, book3}) { // book will be book1, book, book3
    cout << book->toString() << "\n";
    delete book; // free up allocated memory of book1, book2, book3
  }

  // delete book1; //free up allocated memory
  // delete book2; //free up allocated memory
  // delete book3; //free up allocated memory
  // Book *book4 = new (std::nothrow) Book("X MEN", 300); //will get same addr
  // freed from book1

  // Qb
  int n;
  cout << "\nEnter number of books: ";
  cin >> n;
  Book *books = new (std::nothrow) Book[n];

  cout << "Enter information for each book: \n";
  for (int i = 0; i < n; i++) {
    // Read a line from console and set name
    cout << "> Book " << i + 1 << "'s name: ";
    string name;
    std::getline(cin >> std::ws, name);
    books[i].setName(name);

    // Read an integer from console and set price
    int price;
    cout << "price: ";
    cin >> price;
    books[i].setPrice(price);
  }

  Book *mostExp = &books[0];    // assume first book is the most expensive
  for (int i = 1; i < n; i++) { // check with other books
    if (mostExp->getPrice() < books[i].getPrice()) {
      mostExp = &books[i];
    }
  }
  cout << "> Most expensive book: " << mostExp->toString() << "\n";

  delete[] books;

  return 0;
}