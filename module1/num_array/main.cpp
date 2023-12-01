#include <iostream>

int main() {
    int numArray[5];

    for (int i = 0; i < 5; i++) {
        std::cin >> numArray[i];
    }

    // Find the index of the maximum number
    int maxIndex = 0;
    for (int i = 0; i < 5; i++) {
        if (numArray[i] >= numArray[maxIndex]) {
            maxIndex = i;
        } 
    }

    // Calculate the average
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += numArray[i];
    }
    double avgValue = (double) sum / 5;

    // Print out the result
    std::cout << "Maximum value: " << numArray[maxIndex] << std::endl;

    std::cout << "Average value: " << avgValue << std::endl;
}