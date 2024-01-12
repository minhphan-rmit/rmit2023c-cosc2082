#include <iostream>
#include <vector>

using std::cout;
using std::string;
using std::vector;

// Qa
class Book {
private:
  string title;
  int availableCopies;
  vector<string> namesOfBorrowers;

public:
  // Constructor
  Book(string title = "", int availableCopies = 0,
       vector<string> namesOfBorrowers = {})
      : title(title), availableCopies(availableCopies),
        namesOfBorrowers(namesOfBorrowers){};
  /* Note: we can assign vector to another vector directly */

  // Extra function to show information
  void showInfo() {
    cout << "Title = " << title << ", availableCopies = " << availableCopies
         << ", namesOfBorrowers : ";

    for (string name : namesOfBorrowers) {
      cout << name << " ";
    }

    cout << "\n";
  }

  friend class User; // grant access
};

// Qb
class User {
private:
  string name;
  vector<Book *> borrowedBooks; // vector of Book object pointers (like a list of links)

public:
  // Constructor
  User(string name = "", vector<Book *> borrowedBooks = {})
      : name(name), borrowedBooks(borrowedBooks) {}

  /* Function to borrow book */
  bool doBorrow(Book &abook) {
    if (abook.availableCopies == 0) {
      return false;
    }

    // record the book (like a link) in borrowedBooks list of the user
    borrowedBooks.push_back(&abook);

    // record the borrower's name in namesOfBorrowers list of the book
    abook.namesOfBorrowers.push_back(name);

    // reduce its availableCopies
    abook.availableCopies--;

    return true;
  }

  /* Function to return book */
  void doReturn(Book &abook) {
    // remove the book link in borrowedBooks list of the user
    for (int i = 0; i < borrowedBooks.size(); i++) {
      if (borrowedBooks[i] == &abook) {
        borrowedBooks.erase(borrowedBooks.begin() + i);
      }
    }

    // remove the borrower's name in namesOfBorrowers list of the book
    for (int i = 0; i < abook.namesOfBorrowers.size(); i++) {
      if (abook.namesOfBorrowers[i] == name) {
        abook.namesOfBorrowers.erase(abook.namesOfBorrowers.begin() + i);
      }
    }

    // increase its availableCopies
    ;  }

  void showInfo() {
    cout << "Name = " << name << ", Titles of borrowedBooks = ";
    for (Book *book : borrowedBooks) {
      cout << book->title << " ";
    }

    cout << "\n";
  }
};

// Qd
class SuperUser : public User {
public:
  // Constructor
  SuperUser(string name = "", vector<Book *> borrowedBooks = {})
      : User(name, borrowedBooks) {}

  // Function overriding
  bool doBorrow(Book &book1, Book &book2) {
    if (User::doBorrow(book1) && User::doBorrow(book2)) {
      return true;
    }

    return false;
  }
};

int main() {
  // Qa-b

  /* Review: this is the way to request memory allocation and
  intialize values for an array of objects */
  // Book *bookArr = new Book[3]{
  //     Book("Book1", 3, {} ),
  //     Book("Book2", 3, {} ),
  //     Book("Book3", 3, {} )
  // }

  /* Create a vector of three Book objects using dynamic memory allocation */
  vector<Book *> books = {new (std::nothrow) Book("Book0", 4, {}),
                          new (std::nothrow) Book("Book1", 4, {}),
                          new (std::nothrow) Book("Book2", 4, {})};

  // Check memory allocation is successful or not
  for (Book *book : books) {
    if (book == NULL) {
      cout << "Fail to request memory allocation \n";
      return -1;
    }
  }

  // Test methods:
  User user1("User1", {}), user2("User2", {});

  user1.doBorrow(*books[0]);
  user1.doBorrow(*books[1]);
  user2.doBorrow(*books[1]);  

  books[0]->showInfo();
  books[1]->showInfo();

  user1.showInfo();
  user2.showInfo();

  // Qd.
  SuperUser su1("Super User", vector<Book *>{});
  su1.doBorrow(*books[0], *books[2]); // borrow two books
  su1.showInfo();

  // free up memory at the e
  for (Book *aBook : books) {
    delete aBook;
  }

  return 0;
}
