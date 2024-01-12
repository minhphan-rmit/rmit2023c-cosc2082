#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

#define DISCOUNT_RATE 0.05

class Product {
private:
    string name;
    double price;

public:
    // constructor
    Product(string name = "", double price = 0) 
        : name(name), price(price){}
    
    //overload operator == for comparision
    bool operator == (Product another){
        return (this->name == another.name && this->price == another.price);
    }

    void showInfo(){ cout << "\t" << name << ", price = " << price << "\n";}

    //grant access
    friend class Shop;
    friend class CustomerAcc;
};


class Shop {
private:
    string name;
    vector<Product> sellingList;

public:
    //constructor
    Shop (string name = "", vector<Product> sellingList = {})
        : name(name), sellingList(sellingList){}

    //show Information
    void showInfo(){
        cout << "\nSHOP: " << name << ", selling items: \n";
        for (Product pd: sellingList){
            pd.showInfo();
        }
    }
};


class Order {
private:
    int orderID;
    vector<Product> boughtList;  //list of bought products
    double expense; //total expense

public:
    //constructor
    Order(int orderID, vector<Product> boughtList = {}, double expense = 0)
        : orderID(orderID), boughtList(boughtList), expense(expense){}

    void showInfo(){
        cout << "OrderID: " << orderID << ". Bought list: \n";
        for (Product pd: boughtList){
            pd.showInfo();
        }
        cout << "\tTotal expense = " << expense << "\n";
    }

    friend class CustomerAcc;
};



//Class for Custermer CustomerAcc
class CustomerAcc {
private:
    bool isGoldAcc = 0; //normal account by default
    string name;
    vector<Order> orders;

public:
    //constructor
    CustomerAcc(string name = "", bool isGoldAcc = false, vector<Order> orders = {})
        : name(name), isGoldAcc(isGoldAcc), orders(orders){}

    void buyProducts(vector<Product> pdList){
        //caculate total expense
        double totalExpense = 0;
        for (Product pd : pdList){ //loop through all products
            if (isGoldAcc){ //Gold acc: discount 5%
                totalExpense += pd.price* (1 - DISCOUNT_RATE);
            } else { //normal acc: no discount
                totalExpense += pd.price;
            }
        }

        //Assign value for orderID (counting up from 1)
        int orderID = orders.size() + 1; //at the beginning, size is 0 --> 1

        //Create and add a new order into the list
        orders.push_back( Order(orderID, pdList, totalExpense) );
    }

   //show Information
    void showInfo(){
        cout << "\nCUSTOMER: " << name 
             << ", account type = " << (isGoldAcc ? "Gold": "Normal") 
             << ", discountRate = " << (isGoldAcc ? DISCOUNT_RATE : 0) << "\n";
        for (Order od: orders){
            od.showInfo();
        }
    }
};



int main() {
    // Create a shop and add products
    Product pd1("Shoe", 20), pd2("Car", 1000), pd3("Book", 10);
    Shop shop1("Shop1", {pd1, pd2, pd3});
    shop1.showInfo(); 

    //Test normal and gold accounts
    CustomerAcc acc1("NormalAcc", 0);
    acc1.buyProducts({pd1}); //first order
    acc1.buyProducts({pd1, pd2, pd3}); //second order
    acc1.showInfo();

    CustomerAcc acc2("GoldAcc", 1); //gold account
    acc2.buyProducts({pd1});
    acc2.buyProducts({pd1, pd2, pd3});
    acc2.showInfo();

    return 0;
}
