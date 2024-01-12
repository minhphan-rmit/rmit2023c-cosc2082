#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
#define STRSIZE 100

int main() {
    // a)	Read a string from the console input, store the string in character
    // array str. Then print out its all characters, separated by a space.
    char str[STRSIZE];
    cout << "Enter a string: ";
    // std::cin >> str; //only read a word
    cin.getline(str, sizeof(str)); // Read a string with spaces

    // Print out each character
    for (int i = 0; str[i] != '\0'; i++) {
        cout << str[i] << " ";
    }
    cout << "\n\n";

    // b)	Print 1.234 with 9-character width, padded by zeros.
    cout << std::setw(9) << std::setfill('0') << 1.234 << "\n\n";

    // c)	Print 1.234 with precision is 2 digits of fractional part (after decimal point).
    cout << std::setprecision(2) << std::fixed << 1.234 << "\n\n";

    // d)	Read a hexadecimal value (preceded by 0x) into variable hex, then print
    // out its decimal value. Input: 0x10 Output: 16 0x10
    int num;
    cout << "Input a hexa value: ";
    cin >> std::hex >> num;
    cout << num << " " << std::hex << std::showbase << num << "\n\n";
    

    return 0;
}