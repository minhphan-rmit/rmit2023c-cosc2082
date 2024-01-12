#include <cstring>
#include <iostream>
#include <sstream>

#define MAX_BORROWERS 10
#define MAX_BOOKS 5

using std::cin;
using std::cout;
using std::string;

class Book {
private:
  string title;
  int price, availableCopies;
  string borrowerNames[MAX_BORROWERS];

public:
  // Qa.
  // Constructor
  Book(string titleVal = "", int priceVal = 0, int availableCopiesVal = 0, string borrowerNamesVal[] = nullptr)
      : title(titleVal), price(priceVal), availableCopies(availableCopiesVal) {
    for (int i = 0; i < MAX_BORROWERS; i++) {
      if (borrowerNamesVal == nullptr) {
        borrowerNames[i] = "NA"; // default value
      } else {
        borrowerNames[i] = borrowerNamesVal[i];
      }
    }
  }

  // Methods
  bool borrow(string borrowerName) {
    if (availableCopies == 0) { // no available copies
      return false;
    } else {
      for (int i = 0; i < MAX_BORROWERS; i++) { //{"Huy", "Tai", "NA",...."NA"}
        if (borrowerNames[i] == "NA") {
          borrowerNames[i] = borrowerName; // record borrowerName
          break;
        }
      }

      availableCopies--; // reduce number of book copies
      return true;
    }
  }

  void returns(string borrowerName) {
    for (int i = 0; i < MAX_BORROWERS; i++) {
      if (borrowerNames[i] == borrowerName) { // remove borrowerName
        borrowerNames[i] = "NA";
        break;
      }
    }
    availableCopies++; // increase number of book copies
  }

  void showInfo() {
    cout << "title = " << title << ", price = " << price
         << ", availableCopies = " << availableCopies << "\nborrowerNames = ";
    for (int i = 0; i < MAX_BORROWERS; i++) {
      if (borrowerNames[i] != "NA") {
        cout << borrowerNames[i] << "  ";
      }
    }
    cout << "\n\n";
  }

  // declare friend to grant access to private attributes
  friend class User;
  // friend bool User::doBorrow(Book* abook);
  friend Book operator+(int num, Book &aBook);

  // Qc: Book++  (postfix)
  Book operator++(int) {
    Book result = *this; // save original values
    availableCopies++;   // increase number of copies
    return result;       // return orignal values
  }
};

// Qc: int n + Book
Book operator+(int num, Book &aBook) {
  aBook.price += num;
  return aBook;
}

// Qb.
class User {
public:
  string name;
  Book *borrowedBooks[MAX_BOOKS];

  // constructor
  User(string nameVal = "", Book *borrowedBooksVal[] = nullptr)
      : name(nameVal) {
    for (int i = 0; i < MAX_BOOKS; i++) {
      if (borrowedBooksVal == nullptr) {
        borrowedBooks[i] = nullptr; // default value
      } else {
        borrowedBooks[i] = borrowedBooksVal[i];
      }
    }
  }

  // methods
  bool doBorrow(Book *abook) {
    if (abook->borrow(name) == false) {
      return false; // borrow fail: no avaiable copies
    }

    // borrow successfully
    for (int i = 0; i < MAX_BOOKS; i++) {
      if (borrowedBooks[i] == nullptr) {
        borrowedBooks[i] = abook; // record borrowed book
        break;
      }
    }
    return true;
  }

  void doReturn(Book *abook) {
    abook->returns(name);

    for (int i = 0; i < MAX_BOOKS; i++) {
      if (borrowedBooks[i] == abook) {
        borrowedBooks[i] = nullptr; // remove borrowed book
        break;
      }
    }
  }

  void showInfo() {
    cout << "name = " << name << ", borrowedBooks = ";
    for (int i = 0; i < MAX_BOOKS; i++) {
      if (borrowedBooks[i] != nullptr) {
        cout << borrowedBooks[i]->title << "  ";
      }
    }
    cout << "\n\n";
  }

  // Qc. User >> Book
  void operator>>(Book &abook) { doReturn(&abook); }
};



int main() {
  // Qa
  cout << ">>> Testing for Question a: \n";
  Book book1("Book1", 100, 10);
  Book book2("Book2", 200, 8);
  book1.borrow("An");
  book1.borrow("Huy");
  book1.returns("An");
  book2.borrow("Petter");
  book2.borrow("John");
  book2.returns("John");
  book1.showInfo();
  book2.showInfo();

  // Qb
  cout << "\n\n>>> Testing for Question b: \n";
  User User1("User1");
  User1.doBorrow(&book1);
  User1.doBorrow(&book2);
  User1.doReturn(&book2);
  User1.showInfo();
  book1.showInfo();
  book2.showInfo();

  // Qc
  cout << "\n\n>>> Testing for Question c: \n";
  User1 >> book1;
  book1++;
  500 + book1;
  User1.showInfo();
  book1.showInfo();

  return 0;
}