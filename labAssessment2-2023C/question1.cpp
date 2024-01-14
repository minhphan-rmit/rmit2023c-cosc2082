/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 2
    Author: Phan Nhat Minh
    ID: 3978598
    Compiler used: 13.2.0
    Created  date: 13/01/2024
    Acknowledgement: Canvas, Lecture slides, www.geeksforgeeks.org, www.tutorialspoint.com, www.learncpp.com, www.w3schools.com, www.programiz.com, cplusplus.com
*/
#include <iostream>
#include <fstream>

std::string createFileName(const std::string& name) {
    return name + ".dat";
}

int main() {
    // Variable initialization
    std::string studentName, studentID;
    
    // Prompt for name and id input
    std::cout << "Input your student name: ";
    getline(std::cin, studentName);
    std::cout << "Input your student id: ";
    std::cin >> studentID;

    // Creating the file name and open the file
    std::string fileName = createFileName(studentName);
    std::ofstream file(fileName);

    // Check if the file is open
    if (file.is_open()) {
        // Writing data to the file
        file << "Student Name: " << studentName << "\n";
        file << "Student ID: " << studentID << "\n";

        // Closing the file
        file.close();

        // Confirmation message
        std::cout << "Your data is saved in " << fileName << "!\n";
    } else {
        // Error message
        std::cout << "Error opening file\n";
    }

    return 0;
}
