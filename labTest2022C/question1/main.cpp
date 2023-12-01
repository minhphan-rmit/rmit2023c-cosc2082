#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <limits>

using std::cout;
using std::cin;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Invalid argument!";
        return -1;
    }

    if (strcmp(argv[1], "-w") == 0) {
        std::ofstream outFile("sellingItems.dat", std::ios::app);

        if (!outFile) {
            std::cerr << "Unable to open/write file!";
            return -1;
        }

        int numOfItems;
        cout << "Enter total number of items: ";
        cin >> numOfItems;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline left in the buffer

        for (int i = 0; i < numOfItems; i++) {
            std::string itemName;
            int price;

            cout << "Enter name of item: ";
            std::getline(cin, itemName);

            cout << "  >  price: ";
            cin >> price;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline left in the buffer

            outFile << itemName + " " + std::to_string(price) + "\n";
        }

        outFile.close();
    } else if (strcmp(argv[1], "-r") == 0) {
        std::ifstream inFile("sellingItems.dat");

        if (!inFile) {
            std::cerr << "Unable to open/read file!";
            return -1;
        }

        std::string line;
        while (std::getline(inFile, line)) { // Assuming each line is an item followed by a price
            cout << line << "\n";
        }

        inFile.close();
    } else if (strcmp(argv[1], "-s") == 0) {
        std::ifstream inFile("sellingItems.dat");

        if (!inFile) {
            std::cerr << "Unable to open/read file!";
            return -1;
        }

        std::string item;
        int price;
        std::string minItem;
        int minPrice = INT_MAX;

        while (inFile >> item >> price) {
            if (price < minPrice) {
                minPrice = price;
                minItem = item;
            }
        }

        if (minPrice != INT_MAX) {
            cout << minItem + " : " + std::to_string(minPrice) << "\n";
        } else {
            cout << "No items found or all items have prices >= " << INT_MAX << "\n";
        }

        inFile.close();
    } else {
        std::cerr << "Invalid action!";
        return -1;
    }

    return 0;
}
