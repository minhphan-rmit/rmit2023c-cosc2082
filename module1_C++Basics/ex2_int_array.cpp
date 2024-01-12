#include <iostream>
using std::cin;
using std::cout;

#define ARRSIZE 5

int main() { 
    int arr[ARRSIZE];

    //Input 5 integers into an array
    cout << "Enter 5 integers: \n";
    for (int i = 0; i < ARRSIZE; i++) {
        cin >> arr[i];
    }

    /* Caculate max and average */
    int max = arr[0];
    int sum = arr[0];
    for (int i = 1; i < ARRSIZE; i++) {
        //update max if found larger value
        if (max < arr[i]) {
            max = arr[i];
        }
        //caculate sum
        sum = sum + arr[i]; 
    }
    double average = (double)sum/ARRSIZE;

    cout << "Max = " << max
         << ", Average = " << average << "\n";

    return 0; 
}