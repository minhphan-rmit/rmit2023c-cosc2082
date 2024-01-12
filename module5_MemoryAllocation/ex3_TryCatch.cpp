#include <iostream>

int main() {

    //Qa
    int a, b;
    std::cout << "Enter a and b for division a/b: ";
    
    try {
        std::cin >> a >> b;
        if (b == 0) {
            throw -1; //throw custom error (an integer)
        }
    } catch (int errorcode) {
        std::cerr << "b is 0 !!! Error code: " << errorcode << "\n";

        do {
            std::cout << "Please enter the value for b again: ";
            std::cin >> b;
        } while (b == 0);
    }

    std::cout << "Result: a/b = " << (float) a/b << "\n";


    //Qb
    int count = 0;
    std::cout << "\n\nRequest memory allocation ....\n";

    while (1) {
        //request memory allocation (1MB = 1024KB = 1024*1024 bytes)
        try {
            char *ip = new char[1024*1024]; //1MB
            count++;

            //print out address of allocated memory locations
            //std::cout   << "Block " << count << ", address = " << (void *) ip << "\n";
        } catch (std::bad_alloc errorcode) { //Handles std::bad_alloc exception
            std::cerr << "\nbad_alloc exception caught !\n";
            std::cerr << "Total memory allocated: " << count << " MB\n";
            break; //break the while loop
        }

    }   

    std::cout << "\nEnd of program !";

    return 0;
}