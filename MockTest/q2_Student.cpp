/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2022-3
    Lab Assessment: 1
    Author: Your name (e.g. Nguyen Van Minh)
    ID: Your student id (e.g. 1234567)
    Compiler used: Compiler version (e.g. g++ 8.1.0, type "g++ --version" to
    check) Created  date: dd/mm/yyyy (e.g. 12/11/2021) Acknowledgement: List the
    resources that you use to complete this assessment (write 'None' if you don't
    use any).
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::string;

#define NUM_SCORES 3

class Student {
private:
    string name;
    int scores[NUM_SCORES];

public:
    // Constructor
    Student(string nameVal = "", int scoresVal[] = nullptr) {
    name = nameVal;
    if (scoresVal != nullptr)
        for (int i = 0; i < NUM_SCORES; i++) {
            scores[i] = scoresVal[i];    
        }
    }  

    // Qa. function to input data
    void inputData   () {
        cout << "\nInput name: ";
        std::getline(cin >> std::ws, name);

        cout << "Input scores: ";
        for (int i = 0; i < NUM_SCORES; i++) {
            cin >> scores[i];
        }
    }

    // function to show information
    void showInfo() {
        cout << name << "\t,";
        for (int i = 0; i < NUM_SCORES; i++) {
            cout << " " << scores[i];
        }
        cout << ", avg = " << std::fixed << std::setprecision(3) << this->avgScore() << "\n";
	}

    // Qb. Declare friend to grant access to private attributes
    friend Student operator + (int n, Student stu);

    // Qb. write extra function to get average score
    double avgScore() {
        int sum = 0;
        for (int i = 0; i < NUM_SCORES; i++) {
            sum += scores[i];
        }

        return (double)sum / NUM_SCORES;
    }

    // Qb. Operator overloading function:
    // object1  > object2
    bool operator>(Student &stu2) {
        return this->avgScore() > stu2.avgScore() ? true : false;
    }

    // Qc
    void setName(std::string name_val) { name = name_val; }

    void setScores(std::string score_val) { // input a string
        std::stringstream sstr;
        sstr << score_val; // store in stringstream
        for (int i = 0; i < NUM_SCORES; i++) {
            sstr >> scores[i]; // extract each number from stringstream
        }
    }
};


// Qb. Operator overloading function:
// cin >> object  : first operand is not an object of the class
std::istream &operator>>(std::istream &is, Student &stu) {
    stu.inputData();
    return is;
}
  
// cout << object  : first operand is not an object of the class
std::ostream &operator<<(std::ostream &os, Student &stu) {
    stu.showInfo();
    return os; 
}     

// UPDATE: int n + object (instead of  float n + object, since scores are int)
// int n  + object: return a result object that has same name, but all scores
// are increased by n.
Student operator+(int n, Student stu) {
    Student result = stu;
    for (int i = 0; i < NUM_SCORES; i++) {
        result.scores[i] += n;
    }
    return result;
}




int main() {
    std::fstream myFile;
    Student stu1, stu2;

    // Qa
    stu1.inputData();
    cout << "> Qa. Student 1's info: ";
    stu1.showInfo();

    // Qb
    cin >> stu2;
    cout << "> Qb. Student 2's info: " << stu2;

    cout << "\n> Student 1 has "
         << ((stu1 > stu2) ? "higher " : "lower or equal ")
         << "average score than Student 2 \n";

    Student stu3 = 10 + stu2;
    cout << "\n> Student 3's info: " << stu3;

    // Qc.
    Student stuArr[10];
    myFile.open("data.txt", std::ios::in);
    if (!myFile) {
        cout << "Fail to open/create file \n";
        return -1;
    }


    // read in information from the text file
    for (int i = 0; i < 10; i++) {
        string tempStr;
        // read the name (up to the delimeter ',')
        std::getline(myFile, tempStr, ',');
        stuArr[i].setName(tempStr);

        // read the scores
        std::getline(myFile, tempStr);
        stuArr[i].setScores(tempStr);
    }
    myFile.close();

    cout << "\n> Qc. All information read from the file: \n";
    for (int i = 0; i < 10; i++) {
        stuArr[i].showInfo();
    }

    // find student with highest average value
    Student bestStu = stuArr[0];
    for (int i = 0; i < 10; i++) {
        if (bestStu.avgScore() < stuArr[i].avgScore()) {
            bestStu = stuArr[i];
        }
    }
    cout << "\n> Student with highest average score: \n";
    bestStu.showInfo();

    return 0;
}