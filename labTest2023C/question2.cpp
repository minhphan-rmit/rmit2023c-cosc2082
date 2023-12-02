/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 1
    Author: Phan Nhat Minh
    ID: 3978598
    Compiler used: 13.2.0
    Created  date: 02/12/2023
    Acknowledgement: Canvas, Lecture slides, Exercise solutions, www.geeksforgeeks.org, www.tutorialspoint.com, www.learncpp.com, www.w3schools.com, www.programiz.com, cplusplus.com
*/
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>

bool isHex(char* hexnum) {
    // Check if it contains "0x"
    if (strlen(hexnum) <= 2) {
        return false;
    }

    // Check first two character ("0x" or "0X")
    if (strncmp(hexnum, "0x", 2) != 0 && strncmp(hexnum, "0X", 2) != 0) {
        return false;
    }

    // Check for all hexa digits (must be 0-9, A-Z --> use isxdigit function)
    for (int i = 2; i < strlen(hexnum); i++) {
        if (!isxdigit(hexnum[i])) {
        return false;
    }
    }

    return true;
}

bool isInt(char* num) {
    // Check if all the characters in the num char is digit or not
    for (int i = 0; i < strlen(num); i++) {
        if (!isdigit(num[i])) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are passed
    if (argc != 4) {
        std::cerr << "Invalid arguments!" << std::endl;
        return 1;
    }

    // Get the first number from the argument line
    char* hexnum1 = argv[1];
    int num1;
    std::stringstream ss1;
    ss1 << argv[1];
    // If it is hex number then pass it to num1 using std::hex
    if (isHex(hexnum1)) {
        ss1 >> std::hex >> num1;
    } else if (isInt(hexnum1)) {
        ss1 >> num1;
    } else {
        std::cerr << "Incorrect number format!" << std::endl;
        return 1;
    }

    // Get the first number from the argument line
    char* hexnum2 = argv[3];
    int num2;
    std::stringstream ss2;
    ss2 << argv[3];
    // If it is hex number then pass it to num1 using std::hex
    if (isHex(hexnum2)) {
        ss2 >> std::hex >> num2;
    } else if (isInt(hexnum2)) {
        ss2 >> num2;
    } else {
        std::cerr << "Incorrect number format!" << std::endl;
        return 1;
    }

    // Store the operator
    char op = argv[2][0];

    // Perform the operation and store the result
    int result;
    if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else {
       std::cerr << "Invalid operator. Please use + or -." << std::endl;
        return 1;
    }

    // Output the result
    std::cout << "Result is: " << result << std::endl;

    return 0;
}
