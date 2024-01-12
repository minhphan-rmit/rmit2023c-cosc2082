// Develop a template function min3 that takes three arguments of the same type and returns the
// least of these arguments.

#include <iostream>
using std::string;
using std::cout;

template <typename type>
void min3(type num1, type num2, type num3){
    type temp = (num1 < num2) ? num1 : num2; //min of num1 and num2
    type min = (temp < num3) ? temp : num3;

    cout << "The min of " << num1 
         << ", " << num2 
         << ", " << num3
         << " is " << min << "\n";
}


int main(){
    min3<int> (1, 0, 2);
    min3<float> (1.5, 0.5, 3.0);
    min3<string> ("Hello", "Hi", "Morning");

    return 0;
}