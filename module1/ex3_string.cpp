
#include <iostream>
using std::cin;
using std::cout;

#define MAXSIZE 100
int main() {
    // Input the string
    char str[MAXSIZE];
    cout << "Input a string: ";
    cin.getline(str, sizeof(str));//(where you want them stored,maximum number)

    int digit_sum = 0;

    for (int i = 0; str[i] != '\0'; i++) { //Loop through all characters in the string
        // Convert characters from lowercase to uppercase and vice versa
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }

          // Find the sum of all digit values in the string
          if (isdigit(str[i])){
              digit_sum += (str[i] - '0'); //get the digit value and add to sum
           }
      }
  
        cout << "-> Converted String: " << str << "\n"
           << "-> Sum of all digits in the string: " << digit_sum << "\n";

    return 0;
}
