#include <iostream>
#include <string>

class EWallet {
private:
    std::string name;
    double balance;

public:
    // Constructor
    EWallet(std::string name, double balance) : name(name), balance(balance) {}

    std::string getName() {
        return this->name;
    }

    double getBalance() {
        return this->balance;
    }

    void setName(std::string nameVal) {
        this->name = nameVal;
    }

    void setBalance(double amt) {
        this->balance = amt;
    }

    // Method to pay
    bool pay(double amount, const std::string& coupon) {
        double discount = (coupon == "BLACKFRIDAY") ? 0.7 : 1.0;
        double deductedAmount = amount * discount;

        if (balance >= deductedAmount) {
            balance -= deductedAmount;
            std::cout << "Payment successful. Deducted: " << deductedAmount << std::endl;
            return true;
        } else {
            std::cout << "Payment failed. Insufficient balance." << std::endl;
            return false;
        }
    }

    // Overloading >> operator
    friend void operator>>(double amount, EWallet& obj) {
        obj.balance += amount;
    }
};

class User {
    private:
    std::string name;
    std::string pwd;
    EWallet acc;

    public:
    User(std::string nameVal, std::string pwdVal, EWallet userAcc)
        :name(nameVal), pwd(pwdVal), acc(userAcc) {}

    EWallet getUserAcc() {
        return acc;
    }

    bool verifyPass() {
        std::string pass;

        std::cout << "Input your password: ";
        std::cin >> pass;

        if (pass == this->pwd) {
            return true;
        } else {
            std::cout << "Incorrect password.";
            return false;
        }
    }

    bool doPayment() {
        if (verifyPass()) {
            double payAmt;
            std::string discountCp;

            std::cout << "Amount: ";
            std::cin >> payAmt;

            std::cout << "Coupon: ";
            std::cin >> discountCp;

            this->acc.pay(payAmt, discountCp);

            return true;
        } else {
            return false;
        }
    }

    friend void operator>>(User userA, User userB) {
        if (userA.acc.getBalance() > 0) {
            userB.acc.setBalance(userB.acc.getBalance() + userA.acc.getBalance());
            userA.acc.setBalance(0);
        }
    } 

    void operator<<() {
        
    }
};

User secSmallestBal(User users[4]) {
    int minIndex = 0;

    for (int i = 0; i < 4; i++) {
        if (users[i].getUserAcc().getBalance() < users[minIndex].getUserAcc().getBalance()) {
            minIndex = i;
        }
    }

    int secondSmallestIndex = 0;

    for (int i = 0; i < 4; i++) {
        if (users[i].getUserAcc().getBalance() < users[minIndex].getUserAcc().getBalance()
        && users[i].getUserAcc().getBalance() > users[minIndex].getUserAcc().getBalance()) {
            secondSmallestIndex = i;
        }
    }

    return users[secondSmallestIndex];
}

// Test the class
int main() {
    User users[4] = {
        User("Minh", "minh123", EWallet("Momo", 1000)),
        User("Cuong", "cuong234", EWallet("ZaloPay", 700)),
        User("Loc", "loc345", EWallet("Paypal", 500)),
        User("Man", "man456", EWallet("VNPay", 940))
    };
}
