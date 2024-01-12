#include <fstream>
#include <iostream>
using std::cin;
using std::cout;
using std::string;

class Student {
private:
  int score;
  string password;

public:
  string name;

  Student(string nameVal = "", int scoreVal = 0, string pwdVal = "")
      : name(nameVal), score(scoreVal), password(pwdVal) {}

  void showInfo() {
    cout << "Name = " << name << ", Score = " << score << "\n";
  }

  int getScore() { return score; }

  /* Q3:  Method to change password */
  void changePwd() {
    // Check if there is an existing password
    std::fstream myfile;
    myfile.open(name + ".dat", std::ios::in);

    if (myfile) {
      std::getline(myfile, password); // read a line from the file
    }
    myfile.close();

    if (password == "") { // No existing password
      cout << "No existing password. Please set your password now: ";

    } else { // we have existing password
      cout << "Please enter your current password: ";
      string in_pwd;
      std::getline(cin >> std::ws,
                   in_pwd); // read a line and store to in_pwd string

      if (in_pwd == password) { // user enter correct password
        cout << "Correct. Now set your new password: ";
      } else { // User enter wrong password
        std::cerr << "Incorrect Password";
        return; // Stop the function
      }

      /* Allow user to set the new password */
      std::getline(cin >> std::ws,
                   password); // read a line and store to pwd string

      myfile.open(name + ".dat", std::ios::out); // open the file for writing
      myfile << password;                        // save into the file
      myfile.close();
    }
  };

  int main() {
    // Test the class method
    Student stu("Thu Nguyen", 80);
    stu.changePwd();
    stu.changePwd();

    return 0;
  }