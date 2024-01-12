#include <iostream>
#include <vector>
#include <fstream>
using std::cout; 
using std::cin;
using std::string;

#define FILENAME "dataFile.dat"

class Student {
protected:
    string name;
    int id; 

public:
    Student(string nameVal = "", int idval = 0) 
        : name(nameVal), id(idval){}

    friend class System; //declare friend to grant access
};


class System {
private:
    std::vector<Student> students{};

public:
    System(){} //constructor

    //Qa:
    //Extra function to check if a student is in the system or not
    int findStudent(int id){
        for (int i = 0; i < students.size(); i++){
            if (students[i].id == id){
                return i; //return position if matched
            }
        }
        return -1; //return -1 if does not matched
    }

    //Function to add student
    bool addStudents(){
        int id;
        cout << "Input student ID: "; cin >> id;

        int position = findStudent(id); 
        if ( position >= 0) { //Student is already in the system
            cout << "Student is already in the system \n";
            return false;

        } else { //Add new student
            string name;
            cout << "Input student name: "; 
            getline(cin >> std::ws, name);

            students.push_back( Student(name, id) );
            cout << "Added to the system successfully \n";
            return true;
        }
    }

    //Function to remove student
    bool removeStudent(){
        int id;
        cout << "Input student ID: "; cin >> id;

        int position = findStudent(id); 
        if ( position >= 0) { //Student is in the system
            students.erase( students.begin() + position );
            cout << "Removed from the system successfully \n";
            return true;

        } else { //Student is not found in the system
            cout << "Student is not found in the system \n";
            return false;
        }
    }

    //Qb:
    //Function to show info of all students
    void showAllStudents(){
        cout << "\nAll Students in the School system : \n";
        for (Student &stu: students){
            cout << stu.name << " : " << stu.id << "\n";
        }
    }

    //Function to save info of all students to file
    bool saveAllStudents(){
        std::ofstream dataFile;
        dataFile.open(FILENAME, std::ios::out);
        if (!dataFile.is_open()) {
            cout << "Fail to create/open file \n";
            return false;
        }

        //Store in the file
        for (Student &stu: students){
            dataFile << stu.name << " : " << stu.id << "\n";
        }
        return true;
    }

    //Function to reload info of all students (to student list)
    bool reloadData(){
        std::ifstream dataFile;
        dataFile.open(FILENAME, std::ios::in);
        
        if (!dataFile.is_open()) {
            //cout << "Fail to ospen file \n";
            return false;
        }

        /* Reload data from the file */
        string name, idString;
        while (1) {
            //Read data from file
            getline(dataFile, name, ':'); //read name until seeing ':' character
            getline(dataFile, idString);  //read id
            if (name == "" || idString == ""){ //ends when there is no more data
                break;
            }

            //Store into the student list
            students.push_back( Student(name, std::stoi(idString)));
        }

        return true;
    }
};



int main(){
    //std::vector<Student> students;
    System sys; //create an object of System

    //Qa. Test functionalities
    // sys.addStudents();
    // sys.removeStudent();

    //Qb. Full system
    //Load all data from file at begining (depend on how you save it before)
    if ( !sys.reloadData() ) {
        //cout << "No Data inputted or Fail to load data \n";
    }

    //Provide a menu for all functionalities
    while (1) {
        cout << "\nSchool Management System \n"
        "1. View all students \n"
        "2. Add Student \n"
        "3. Remove Student \n"
        "4. Exit \n"
        "Enter Your Choice: ";
        int choice; cin >> choice;

        if (choice == 1){ //View all students
            sys.showAllStudents();

        } else if (choice == 2){ //Add Student
            sys.addStudents();

        } else if (choice == 3){ //Remove Student
            sys.removeStudent();

        } else if (choice == 4){ //Exit
            //Save all data before exit
            if ( !sys.saveAllStudents() ){
                cout << "Error: Fail to save data for your app \n";
            } 
            cout << "*** Bye. Have a good day ! ***";
            break;
        } 
    }

    return 0;
}