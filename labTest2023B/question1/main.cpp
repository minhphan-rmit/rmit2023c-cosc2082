#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

// Function to sum digits of an integer
int sumDigit(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to check if a number is a palindrome
bool isPalindrome(int n) {
    int reversed = 0, original = n;
    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

// Function to check if the sum of digits is a palindrome
bool checkPal(int n) {
    return isPalindrome(sumDigit(n));
}

// Function to recommend changes to make a sum a palindrome
std::string recPal(int sum) {
    for (int i = 1; i <= 9; ++i) {
        if (isPalindrome(sum + i))
            return "Add " + std::to_string(i) + " to make it a palindrome.";
        else if (isPalindrome(sum - i))
            return "Minus " + std::to_string(i) + " to make it a palindrome.";
    }
    return "No single digit addition/subtraction can make it a palindrome.";
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Error: Incorrect number of arguments.\n";
        return 1;
    }

    std::ifstream inFile(argv[1]);
    std::ofstream outFile("Result.txt");
    int number;

    if (!inFile) {
        std::cout << "Error: Unable to open file.\n";
        return 1;
    }

    while (inFile >> number) {
        int sum = sumDigit(number);
        std::string result = std::to_string(number) + ": Result " + std::to_string(sum) + " is ";
        result += checkPal(number) ? "a palindrome.\n" : "not a palindrome.\n" + recPal(sum) + "\n";
        
        std::cout << result;
        outFile << result;
    }

    inFile.close();
    outFile.close();
    return 0;
}