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

int main() {
    // Declare variables for total seconds, hours, minutes, and seconds
    int totalSeconds, hours, minutes, seconds;

    // Prompt user to input the total amount of seconds
    std::cout << "Input total amount of seconds: ";
    std::cin >> totalSeconds;

    // Calculate hours by dividing the total seconds by 3600 (seconds in an hour)
    hours = totalSeconds / 3600;

    // Calculate remaining seconds after converting to hours
    int remainingSeconds = totalSeconds % 3600;

    // Calculate minutes by dividing the remaining seconds by 60
    minutes = remainingSeconds / 60;

    // Remaining seconds are the remainder of the division above
    seconds = remainingSeconds % 60;

    // Output the result in the format of hours, minutes, and seconds
    std::cout << "It is " << hours << " hour(s), " << minutes << " minute(s) and " << seconds << " second(s)." << std::endl;

    return 0;
}
