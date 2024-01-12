#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::cout;


/* Class Prototype 
(declare Department class to use this data type in Staff class)*/
class Department;

class Staff {
private: 
    string name;
    string deptName;

public:
    //Constructors
    Staff(string name = "", string deptName = "")
        : name(name), deptName(deptName){}

    //Methods: declare first, define later
    //(since the class Deparment is not fully defined above)
    void joinDept(Department &dept);  
    void leaveDept(Department &dept);

    friend class Department; //grant access
};



//Define Department class here
class Department {
private:
    string name;
    string location;
    vector<Staff*> staffs;

public:
    //Constructors
    Department(string name = "", string location = "", vector<Staff*> staffs = {})
        : name(name), location(location), staffs(staffs){}

    void showInfo(){
        cout    << "\nDept Name = " << name
                << "\n> Location = " << location
                << "\n> Current staffs: \n";

        for (auto eachStaff: staffs){
            cout << "\t" << eachStaff->name << "\n";
        }
    }

    friend class Staff;  //grant access
}; 



//Define join and leave methods of Staff class 
//(after the class Deparment has been fully defined)
void Staff::joinDept(Department &dept){
    //insert current staff in to the list
    dept.staffs.push_back(this);

    //update the department name of the staff
    deptName = dept.name;
}


void Staff::leaveDept(Department &dept){
    //find and remove current staff from the list
    for (int i = 0; i < dept.staffs.size(); i++) {
        if (dept.staffs[i] == this) {
            dept.staffs.erase( dept.staffs.begin() + i );
        }
    }

    //remove the department name of the staff
    deptName = ""; //assign it by an empty string
}


//Academic Deparment (subtype of Department)
class AcadDept: public Department {
private:
    int numOfCourses;

public:
    //Constructor
    AcadDept(string name = "", string location = "", 
            vector<Staff*> staffs = {}, int numOfCourses = 0)
        : Department (name, location, staffs), numOfCourses(numOfCourses) {}

    void showInfo() {
        Department::showInfo(); //reuse the function of parent class
        cout << "> numOfCourses = " << numOfCourses << "\n";
    }
};




//Non-academic Deparment (subtype of Department)
class NonAcadDept: public Department {
private:
    int numOfServices;

public:
    //Constructor
    NonAcadDept(string name = "", string location = "", 
                vector<Staff*> staffs = {}, int numOfServices = 0)
        : Department (name, location, staffs), numOfServices(numOfServices) {}

    void showInfo() {
        Department::showInfo(); //reuse the function of parent class
        cout << "> numOfServices = " << numOfServices << "\n";
    }
};



int main() {
    Staff staff1("staff 1", "");
    Staff staff2("staff 2", "");
    Staff staff3("staff 3", "");
    
    AcadDept dept1("SSET", "Building 2", {}, 10);
    NonAcadDept dept2("ITS",  "Building 1", {}, 5);

    staff1.joinDept(dept1);
    staff2.joinDept(dept2);
    staff3.joinDept(dept1);

    dept1.showInfo();
    dept2.showInfo();


    return 0;
}  