#include <iostream>
using std::cin;
using std::cout;
using std::string;

int main() {
    string str1, str2;
  
    cout << "Enter the first string: ";
    getline(cin, str1);  

    cout << "Enter the second string: ";
    //cin.ignore(100, '\n'); //don't ignore() here since we use getline() above
    getline(cin, str2);  

    //Qa: revert string 1
    //swap first characters with the last characters until the middle
    for (int i = 0, j = str1.length() - 1;   i < j;   i++, j--) {                                                                                     
        char tmp = str1[i];
        str1[i] = str1[j];
        str1[j] = tmp;
    }
    cout << "Str1 after being reverted: " << str1 << "\n";


    //Qb: convert from lowercase to uppercase and vice versa
    // ? :  is called "conditional operator"
    for (int i = 0; i < str2.length(); i++) { 
        str2[i] = isupper(str2[i]) ? tolower(str2[i]) : toupper(str2[i]) ;
    }
    cout << "Str2 after being converted: " << str2 << "\n";


    /* To use with C-type string: 
    include <cstring.h>
    + use cin.getline(str, sizeof(str))
    + use strlen(str) instead of .length()
    */


    return 0;
}