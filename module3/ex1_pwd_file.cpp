#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::string;

int main () {
    std::fstream myfile;
    string pwd;
    int choice;

    cout <<    "Password management program: \n" 
                    "1. Save your password \n"
                    "2. Read your password \n"
                    "Your choice: ";
    cin >> choice;

    if (choice == 1) { /* Save your password */
        myfile.open("pwd.dat", std::ios::out); 

        if (!myfile) { 
            cout << "Fail to create/open file \n";
            return -1;
        }

        //Get the password from console and save to file
        cout << "Enter the password: ";
        cin.ignore(1, '\n'); //ignore previous '\n' entered by user
        getline(cin, pwd); //read a line from console

        myfile << pwd;
        myfile.close();
        cout << "Saved to the file! \n";

    } else { /* Read your password */
        myfile.open("pwd.dat", std::ios::in);
        if (!myfile) { 
            cout << "Fail to open file \n";
            return -1;
        }

        getline(myfile, pwd); //read a line from file
        myfile.close();
        cout   << "Read your password from the file: " 
                    << pwd << "\n";
    }

   return 0;
}


//NOTE: getline() : https://cplusplus.com/reference/string/string/getline/?kw=getline