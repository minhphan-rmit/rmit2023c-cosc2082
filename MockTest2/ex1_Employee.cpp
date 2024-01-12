#include <iostream>
using std::cout;
using std::string;

class Employee {
protected:
  string name;
  double salary;

public:
  // constructor
  Employee(string name = "", double salary = 0) : name(name), salary(salary){};

  void showInfo() { cout << name << ", salary = " << salary; }
};  

class Manager : public Employee { // inheritance
private:
  double allowance;

public:
  // constructor
  Manager(string name = "", double salary = 0, int allowance = 0)
      : Employee(name, salary), allowance(allowance){};

  void showInfo() {
    cout << name << ", salary = " << salary << ", allowance = " << allowance;
  }

  // extra function to get total income
  double getTotalIncome() { return salary + allowance; }
};

int main() {
  // Qa.
  Employee staff1("Erling Haaland", 300000);
  staff1.showInfo();
  cout << "\n";

  Manager manager1("Pep Guardiola", 400000, 10000);
  manager1.showInfo();
  cout << "\n";

  // Qb.
  // Create and initialize the array (using dynamic memory allocation)
  Manager *managers = new (std::nothrow)
      Manager[5]{Manager("manager1", 1000, 100), Manager("manager2", 3000, 200),
                 Manager("manager3", 2000, 300), Manager("manager4", 4000, 200),
                 Manager("manager5", 2000, 100)};

  if (managers == nullptr) {
    cout << "Fail to request memory allocation \n";
    return -1;
  }

  // Look through all elements to caculate sum and everage
  double incomeSum = 0;
  for (int i = 0; i < 5; i++) {
    incomeSum = incomeSum + managers[i].getTotalIncome();
  }
  cout << "Average of total income = " << incomeSum / 5;

  delete[] managers;

  return 0;
} 
