#include <iostream>
using std::cin;
using std::cout;

int main() {
    float a, b;
    cout << "Enter the a and b of the equation ax + b = 0: ";
    cin >> a >> b;

    if (a == 0) {
        if (b == 0) {
            cout << "The equation has infinite solutions (any value of x)" << "\n";
        } else {
            cout << "The equation has no solution." << "\n";  
        }
    } else { //a != 0
        float x = -b / a;
        cout << "The solution is x = " << x << "\n";
    }

    return 0;
}