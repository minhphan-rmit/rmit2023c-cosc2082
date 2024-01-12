#include <iostream>
#include <sstream>
#include <cstring>

using std::cin;
using std::cout;
using std::string;

int getVal(char str[]){
    std::stringstream ss;
    int value;

    //Put into stringstream
    if (str[0] == '0' && tolower(str[1]) == 'x'){ //hexa num
        ss << std::hex << str; //store in stringstream as hexa value (work both with/without "0x")
    } else { //store in stringstream as normal integer value (decimal)
        ss << str;
    }

    //Get integer value back from stringstream
    ss >> value; 

    return value;
}


int main(int argc, char *argv[]){
    //Get values from commandline arguments and print out result
    cout << "Result is: " ;
    if (strcmp(argv[2], "+") == 0){
        cout << getVal(argv[1]) + getVal(argv[3]);

    } else if (strcmp(argv[2], "-") == 0){ 
        cout << getVal(argv[1]) - getVal(argv[3]);
    }

    return 0;
}