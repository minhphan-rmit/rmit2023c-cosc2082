#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Student {
public:
    std::string name;
    int studentID;

    Student(std::string n, int id) : name(n), studentID(id) {
        std::cout << "Student constructor called\n";
    }

    ~Student() {
        std::cout << "Student destructor called\n";
    }

    std::string toString() {
        return "Student Name: " + name + ", Student ID: " + std::to_string(studentID);
    }
};

class Staff {
public:
    std::string name;
    int staffID;

    Staff(std::string n, int id) : name(n), staffID(id) {
        std::cout << "Staff constructor called\n";
    }

    ~Staff() {
        std::cout << "Staff destructor called\n";
    }

    std::string toString() {
        return "Staff Name: " + name + ", Staff ID: " + std::to_string(staffID);
    }
};

class Tutor : public Student, public Staff {
public:
    Tutor(std::string n, int sid, int tid) : Student(n, sid), Staff(n, tid) {
        std::cout << "Tutor constructor called\n";
    }

    ~Tutor() {
        std::cout << "Tutor destructor called\n";
    }

    void setName(std::string n) {
        Student::name = n;
    }

    void consultation() {
        std::cout << "Doing consultation!\n";
    }

    std::string toString() {
        return Student::toString() + ", " + Staff::toString();
    }
};

void showInfoStudent(Student &stu) {
    std::cout << stu.toString() << std::endl;
}

void showInfoStaff(Staff &staff) {
    std::cout << staff.toString() << std::endl;
}

class SchoolSystem {
public:
    std::vector<Student> students;

    void addStudent() {
        std::string stuName;
        int stuId;

        std::cout << "Enter student's name to add: ";
        getline(std::cin, stuName);

        std::cout << "Enter student's ID to add: ";
        std::cin >> stuId;

        students.push_back(Student(stuName, stuId));

        std::cout << "Student " << stuName << " with ID " << std::to_string(stuId)
        << " added sucessfully!" << std::endl;
    }

    void removeStudent() {
        int stuId;
        std::cout << "Enter student's ID to delete: ";
        std::cin >> stuId;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].studentID == stuId) {
                students.erase(students.begin()+i);
                break;
            }
        }

        std::cout << "Student with ID " << std::to_string(stuId)
        << " added sucessfully!" << std::endl;
    }
};

void viewAllStu() {
    std::fstream stuFile;
    stuFile.open("students.dat", std::ios::in);
    if (!stuFile) {
        std::cout << "Fail to open/create file \n";
        return;
    }


}

void addStu() {}

void removeStu() {}

int main() {
    std::cout << "School Management System" << std::endl;
    std::cout << "1. View all students" << std::endl;
    std::cout << "2. Add student" << std::endl;
    std::cout << "3. Remove student" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    std::fstream stuFile;
    stuFile.open("students.dat", std::ios::in);
    if (!stuFile) {
        std::cout << "Fail to open/create file \n";
    }

    switch (choice)
    {
    case 1:
        ""
        break;
    
    default:
        break;
    }

    return 0;
}
