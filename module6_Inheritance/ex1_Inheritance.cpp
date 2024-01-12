#include <iostream>
#include <sstream>

using std::string;
using std::cin;
using std::cout;


class Student {
protected:
    string name;
    int studentID;

public:
    Student(string nameVal = "", int studentIDval = 0)
    : name(nameVal), studentID(studentIDval) {
        cout << "Constructor of Student class \n";
    }

    ~Student(){ cout << "Destructor of Student class \n"; }

    virtual string toString(){ //virtual function
        std::stringstream sstr;
        sstr << "name = " << name << ", studentID = " << studentID;
        return sstr.str(); //get the string content from the stringstream
    }
};


class Staff {
protected:
    string name;
    int staffID;

public:
    Staff(string nameVal = "", int staffIDval = 0)
    : name(nameVal), staffID(staffIDval) {
        cout << "Constructor of Staff class \n";
    }

    ~Staff(){ cout << "Destructor of Staff class \n"; }

    virtual string toString(){  //virtual function
        std::stringstream sstr;
        sstr << "name = " << name << ", staffID = " << staffID;
        return sstr.str();
    }
};


class Tutor : public Student, public Staff {    //inherits from Student and Staff
//Inherited attributes:   Student::name;  studentID;   Staff::name;  staffID;
public:
    Tutor (string nameVal = "", int studentIDval = 0, int staffIDval = 0)
    : Student(nameVal, studentIDval), Staff(nameVal, staffIDval) {
        cout << "Constructor of Tutor class \n";
    }

    void consultation(){  cout << "Doing consultation \n"; }

    void setName(string nameVal){
        Student::name = nameVal;
        Staff::name = nameVal;
    }

    ~Tutor(){ cout << "Destructor of Tutor class \n"; }

    virtual string toString(){ //function overriding 
        std::stringstream sstr;
        sstr << "name = " << Student::name << ", staffID = " << staffID << ", studentID = " << studentID;
        return sstr.str();
    }
};


void showInfoStudent(Student &stu){
    cout << stu.toString() << "\n";
}

void showInfoStaff(Staff &staff) {
    cout << staff.toString() << "\n";
}

int main(){
    Student stu1("Harry", 111);
    Staff sta1("James", 222);
    Tutor tut1("John", 123, 345);

    showInfoStudent(stu1);
    showInfoStaff(sta1);

    showInfoStudent(tut1);
    showInfoStaff(tut1);

    return 0;
}