#include <iostream>
#include <fstream>
#include <sstream>
using std::cout;
using std::string;

class BankAcc {  
public:
    string name = "";
    float amount = 0;
    
    //Constructor
    BankAcc(string name_val = "", float amount_val = 0) 
        : name(name_val), amount(amount_val){}

    //To get the information as a string
    string toString() {
        std::stringstream info;
        info << "Name: " << name <<    ", Amount: " << amount;
        return info.str();
    }

    //Withdraw function
    int withdraw(float num) {
        if (amount < num) {
            std::cerr << "Not enough money in the account. Fail to withdraw !\n";
            return -1;
        } 
        
        amount -= num;
        std::cout << "Withdrawn successfully\n";
        return 0;
    }
};


int main(int argc, char* argv[]) {
    std::fstream myfile; //file variable should be declared at beginning

    // Qa
    // Init 3 bank accounts
    BankAcc acc1 ("TCB", 1000);
    BankAcc acc2 ("MBB", 1000);
    BankAcc acc3 ("VCB", 3000);

    // Print all info
    std::cout << "All information of 3 accounts:\n";
    std::cout << acc1.toString() << "\n";
    std::cout << acc2.toString() << "\n";
    std::cout << acc3.toString() << "\n";

    // Qb
    std::cout << "\nTest withdraw function on acc1: \n";
    std::cout << "Withdraw 500: "; acc1.withdraw(500);
    std::cout << "Withdraw 700: "; acc1.withdraw(700);

    // Qc
    if (argc != 2) { //Does not have or have incorrect number of cmd args
        return 0;
    }

    //Save to file 
    myfile.open(argv[1], std::ios::out);
    if (!myfile) {
        std::cerr << "Fail to create/ open file " << argv[1] << "\n";
    }

    //Save data
    myfile << acc1.toString() << "\n";
    myfile << acc2.toString() << "\n";
    myfile << acc3.toString() << "\n";

    std::cout << "Saved data to file " << argv[1] << "! \n";
    myfile.close();
    

    return 0;
}
