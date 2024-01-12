#include <iostream>
using std::cin;
using std::cout;
using std::string;

class Student{
private:
    int score; //private attribute

public:
    string name; //public attribute
    
    //constructor
    Student(string nameVal = "", int scoreVal = 0) 
        : name(nameVal), score(scoreVal){}

    //public method
    void showInfo() {
        cout   << "Name = " << name
               << ", Score = " << score << "\n";
    }

    //provide access to the score (read only)
    int getScore() {
        return score;
    }
};



int main() {
    //Qb
    Student stu1("Nguyen Minh", 73), stu2("David James", 85);
    cout << "Two students: \n";
    stu1.showInfo();
    stu2.showInfo();

    //Qc
    Student stuArr[3];
    
    //Print out info of all students
    cout << "\nAll students in the array: \n";
    for (int i = 0; i < 3; i++) {
        stuArr[i].showInfo();
    }

    //Check highest score
    Student max_stu = stuArr[0]; //assume stu0 is the one with highest score
    for (int i = 1; i < 3; i++) { //compare the score with other students' scores
        if (max_stu.getScore() < stuArr[i].getScore()) {
            max_stu = stuArr[i];
        }
    }

    cout << "\nStudent with highest score in the array: \n";
    max_stu.showInfo();

    return 0;
}