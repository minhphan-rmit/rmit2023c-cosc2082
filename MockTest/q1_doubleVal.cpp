/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2022-3
    Lab Assessment: 1
    Author: Your name (e.g. Nguyen Van Minh)
    ID: Your student id (e.g. 1234567)
    Compiler used: Compiler version (e.g. g++ 8.1.0, type "g++ --version" to
    check) Created  date: dd/mm/yyyy (e.g. 12/11/2021) Acknowledgement: List the
    resources that you use to complete this assessment (write 'None' if you
   don't use any).
*/

#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
using std::cout;

// define Constants for different formats of input string
#define INT_TYPE 0
#define FLOAT_TYPE 1
#define HEXA_TYPE 2

// 1st version with int input
int doubleVal(int num) { return num * 2; }

// 2nd version with floating point input
double doubleVal(double num) { return num * 2; }

// 3rd version with input is string (represented hexa number, e.g. "0xAC")
int doubleVal(char hexaStr[]) {
  int val;

  std::stringstream sstr;
  sstr << std::hex
       << hexaStr; // input the string to the stringstream (with hex format)
  sstr >> val;     // extract value from the stringstream (with int format)

  return val * 2;
}

// Check the format of number represented in the string
int checkType(char str[]) {
  // Check hexas
  if (str[0] == '0' && tolower(str[1]) == 'x') {
    return HEXA_TYPE;
  }

  // Check floating type
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == '.') {
      return FLOAT_TYPE;
    }
  }
  return INT_TYPE; // int by default
}

int main(int argc, char *argv[]) {
  int type = checkType(
      argv[1]); // check format of input string (got from commandline argument)

  if (type == HEXA_TYPE) { // hexa
    cout << std::showbase << std::hex << doubleVal(argv[1]);

  } else if (type == FLOAT_TYPE) { // floating point
    cout << std::fixed << std::setprecision(2) << doubleVal(std::stod(argv[1]));

  } else { // integer
    cout << doubleVal(std::stoi(argv[1]));
  }

  return 0;
}
