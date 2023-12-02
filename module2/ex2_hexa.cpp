// Compile: g++ ex2_hexa.cpp -o ex2_hexa.exe
// Run:     ./ex2_hexa.exe 0x2A

#include <cstring>
#include <iostream>
using std::cout;

int main(int argc, char *argv[]) {
  if (argc !=
      2) { // require two arguments, argv[0] by default and argv[1] (hexa num)
    cout << "> Invalid number of user arguments \n";
    return -1; // error code
  }

  char *hexnum =
      argv[1]; // a pointer of char pointed to argv[1] (can be used as a string)
  cout << "hexnum = " << hexnum;

  if (strlen(hexnum) <= 2) {
    cout << "> Do not have hexa digits \n";
    return -2; // another error code for another error type
  }

  // Check first two character ("0x" or "0X")
  if (strncmp(hexnum, "0x", 2) != 0 && strncmp(hexnum, "0X", 2) != 0) {
    cout << "> Do not have 0x/ 0X \n";
    return -3;
  }

  // Check for all hexa digits (must be 0-9, A-Z --> use isxdigit function)
  for (int i = 2; i < strlen(hexnum); i++) {
    if (!isxdigit(hexnum[i])) {
      cout << "Incorrect format";
    }
  }

  // Correct format (passed all checking above)
  cout << "Got valid hex num: " << hexnum;

  return 0;
}