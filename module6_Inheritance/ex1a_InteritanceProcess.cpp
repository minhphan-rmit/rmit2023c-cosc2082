#include <iostream>
#include <vector>
using std::cout; 
using std::cin;
using std::string;

class Student {
public:
    Student(){ cout << "STUDENT constructor \n"; }
    ~Student(){ cout << "STUDENT destructor \n"; }
};

class Staff {
public:
    Staff(){ cout << "STAFF constructor \n"; }
    ~Staff(){ cout << "STAFF destructor \n"; }
};

class Tutor : public Student, public Staff {
public:
    Tutor(){ cout << "TUTOR constructor \n"; }
    ~Tutor(){ cout << "TUTOR destructor \n"; }
};

int main(){
    Tutor tutor1;
}