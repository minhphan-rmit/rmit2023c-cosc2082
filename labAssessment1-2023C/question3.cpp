/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 1
    Author: Phan Nhat Minh
    ID: 3978598
    Compiler used: 13.2.0
    Created  date: 02/12/2023
    Acknowledgement: Canvas, Lecture slides, www.geeksforgeeks.org, www.tutorialspoint.com, www.learncpp.com, www.w3schools.com, www.programiz.com, cplusplus.com
*/
#include <iostream>

class Book {
private:
    std::string title;
    int price;
    int availableCopies;
    std::string borrowerNames[10];

public:
    // Default constructor
    Book() {}

    // Constructor
    Book(std::string title, int price, int copies) : title(title), price(price), availableCopies(copies) {
        for (int i = 0; i < 10; ++i) {
            borrowerNames[i] = "NA";
        }
    }

    // Method to borrow a book
    bool borrow(std::string borrowerName) {
        if (availableCopies <= 0) {
            return false; // Fail to borrow if no copies are available
        }
        for (int i = 0; i < 10; ++i) {
            if (borrowerNames[i] == "NA") {
                borrowerNames[i] = borrowerName;
                availableCopies--;
                return true;
            }
        }
        return false; // No empty slot for the borrower
    }

    // Method to return a book
    void returns(std::string borrowerName) {
        for (int i = 0; i < 10; ++i) {
            if (borrowerNames[i] == borrowerName) {
                borrowerNames[i] = "NA";
                availableCopies++;
                return;
            }
        }
    }

    // Operator overloading for Book++
    Book& operator++() {
        availableCopies++;
        return *this;
    }

    // Operator overloading for int + Book
    friend Book operator+(int n, Book &book) {
        book.price += n;
        return book;
    }

    // Friend function declaration for User >> Book
    // friend void operator>>(User& user, Book& book);

    // Method to display book information
    void displayInfo() {
        std::cout << "Title: " << title << "\nPrice: " << price << "\nAvailable Copies: " << availableCopies << std::endl;
        std::cout << "Borrowers: ";
        for (const auto& name : borrowerNames) {
            std::cout << "[" << name << "] ";
        }
        std::cout << std::endl;
    }
};

class User {
private:
    std::string name;
    Book* borrowedBooks[5];

public:
    // Default constructor
    User() {}
    
    // Constructor
    User(std::string name) : name(name) {
        for (int i = 0; i < 5; ++i) {
            borrowedBooks[i] = nullptr;
        }
    }

    // Method to borrow a book
    bool doBorrow(Book *abook) {
        if (abook->borrow(name)) {
            for (int i = 0; i < 5; ++i) {
                if (borrowedBooks[i] == nullptr) {
                    borrowedBooks[i] = abook;
                    return true;
                }
            }
        }
        return false; // No slot for a new book or borrow failed
    }

    // Method to return a book
    void doReturn(Book *abook) {
        for (int i = 0; i < 5; ++i) {
            if (borrowedBooks[i] == abook) {
                abook->returns(name);
                borrowedBooks[i] = nullptr;
                return;
            }
        }
    }

    // Operator overloading for User >> Book
    friend void operator>>(User& user, Book& book) {
        for (int i = 0; i < 5; ++i) {
            if (user.borrowedBooks[i] == &book) {
                book.returns(user.name);
                user.borrowedBooks[i] = nullptr;
            }
        }
    }
};

int main() {
    // Books initialization
    Book book1("C++ Programming", 50, 5);
    Book book2("Data Structure and Algorithms", 200, 3);

    // Users initialization
    User user1("Minh");
    User user2("Cuong");
    User user3("Man");
    User user4("Loc");

    // Test borrowing and returning
    std::cout << "Borrowing and returning testing" << std::endl;
    if (user1.doBorrow(&book1)) {
        std::cout << "Borrowed successfully!" << std::endl;
    } else {
        std::cout << "Can not borrow!" << std::endl;
    }
    book1.displayInfo();

    user1.doReturn(&book1);
    book1.displayInfo();

    // Borrow fail scenario testing
    std::cout << "Fail borrowing and returning testing" << std::endl;
    // Make the second book out of copies
    user1.doBorrow(&book2);
    user2.doBorrow(&book2);
    user3.doBorrow(&book2);
    book2.displayInfo();

    if (user4.doBorrow(&book2)) {
        std::cout << "Borrowed successfully!" << std::endl;
    } else {
        std::cout << "Can not borrow!" << std::endl;
    }

    user1.doReturn(&book2);
    user2.doReturn(&book2);
    user3.doReturn(&book2);

    // Operator overload testing
    // User >> Book testing
    std::cout << "User >> Book testing" << std::endl;
    user1.doBorrow(&book2);
    user1.doBorrow(&book2);
    user1.doBorrow(&book2);
    book2.displayInfo();
    user1 >> book2;
    book2.displayInfo();

    // ++Book testing
    std::cout << "++Book testing" << std::endl;
    book1.displayInfo();
    ++book1;
    book1.displayInfo();

    // int + Book testing
    std::cout << "Book's price increase testing" << std::endl;
    book2.displayInfo();
    20 + book2;
    book2.displayInfo();

    return 0;
}
