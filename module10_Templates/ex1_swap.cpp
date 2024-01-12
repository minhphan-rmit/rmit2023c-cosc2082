// Exercise 1: Function Template
// Write a function template namely 
// swap which allow to swap the values of two input numbers.

#include <iostream>
#include <string>
using std::string;

template <typename type>
void swap(type &num1, type &num2){
    type temp = num1;
    num1 = num2;
    num2 = temp;
}


int main(){
    int a = 8, b = 10;
    swap<int>(a, b);
    std::cout << "a = " << a;
    std::cout << ", b = " << b;

    return 0;
}