/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 2
    Author: Phan Nhat Minh
    ID: 3978598
    Compiler used: 13.2.0
    Created  date: 13/01/2024
    Acknowledgement: Canvas, Lecture slides, www.geeksforgeeks.org, www.tutorialspoint.com, www.learncpp.com, www.w3schools.com, www.programiz.com, cplusplus.com
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

class Product {
private:
    std::string name;
    double price;
    int stockQuantity;

public:
        // Default constructor
    Product() : name(""), price(0.0), stockQuantity(0) {}

    // Constructors
    Product(const std::string& name, double price, int stockQuantity)
        : name(name), price(price), stockQuantity(stockQuantity) {}

    // Getters
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getStockQuantity() const { return stockQuantity; }

    // Setters
    void setPrice(double newPrice) { price = newPrice; }
    void setStockQuantity(int newQuantity) { stockQuantity = newQuantity; }

    // Methods
    void updateStock(int soldQuantity) {
        if (soldQuantity <= stockQuantity)
            stockQuantity -= soldQuantity;
        else
            std::cout << "Insufficient stock for " << name << std::endl;
    }
};

class Customer {
private:
    std::string name;
    std::map<std::string, int> lastBill;
    int loyaltyPoints;

public:
    // Default constructor
    Customer() : name(""), loyaltyPoints(0) {}

    // Constructors
    Customer(const std::string& name) : name(name), loyaltyPoints(0) {}

    // Getters
    std::string getName() const { return name; }
    int getLoyaltyPoints() const { return loyaltyPoints; }
    const std::map<std::string, int>& getLastBill() const { return lastBill; }

    // Update loyalty points
    void updateLoyaltyPoints(double amount) {
        loyaltyPoints += static_cast<int>(amount);
    }

    // Use loyalty points
    void redeemLoyaltyPoints(int points) {
        if (points <= loyaltyPoints)
            loyaltyPoints -= points;
        else
            std::cout << "Insufficient loyalty points." << std::endl;
    }

    // Record a purchase
    void addPurchase(const std::map<std::string, int>& purchase) {
        lastBill = purchase;
        for (const auto& item : purchase) {
            updateLoyaltyPoints(item.second); // Assuming 1 point per item for simplicity
        }
    }

    // Return a product
    bool returnProduct(const std::string& productName, int quantity, const std::map<std::string, Product>& products) {
        auto it = lastBill.find(productName);
        if (it != lastBill.end() && it->second >= quantity) {
            lastBill[productName] -= quantity;
            updateLoyaltyPoints(-quantity);
            return true;
        }
        return false;
    }
};

class Shop {
private:
    std::string name;
    std::map<std::string, Product> products; 
    std::map<std::string, Customer> customers; 
    std::map<std::string, double> sales;

    // Helper method to calculate bill amount
    double calculateBillAmount(const std::map<std::string, int>& purchasedProducts) {
        double total = 0.0;
        for (const auto& item : purchasedProducts) {
            const auto& productName = item.first;
            int quantity = item.second;
            if (products.find(productName) != products.end()) {
                total += products[productName].getPrice() * quantity;
                products[productName].updateStock(quantity);
                sales[productName] += products[productName].getPrice() * quantity;
            } else {
                std::cout << "Product " << productName << " not found." << std::endl;
            }
        }
        return total;
    }

public:
    Shop(const std::string& name) : name(name) {}

    // Add or update a product
    void addOrUpdateProduct(const Product& product) {
        products[product.getName()] = product;
    }

    // Register a customer
    void addCustomer(const Customer& customer) {
        customers[customer.getName()] = customer;
    }

    // Create and print a bill for a customer
    void printBill(const std::string& customerName, const std::map<std::string, int>& purchasedProducts) {
        if (customers.find(customerName) != customers.end()) {
            double total = calculateBillAmount(purchasedProducts);
            customers[customerName].addPurchase(purchasedProducts);
            std::cout << "Bill for " << customerName << ": $" << total << std::endl;
        } else {
            std::cout << "Customer " << customerName << " not found." << std::endl;
        }
    }

    // Generate a sale report
    void generateSaleReport() const {
        std::cout << "Sale Report for " << name << std::endl;
        double totalRevenue = 0.0;
        std::string bestSellingProduct;
        double maxSales = 0.0;

        for (const auto& sale : sales) {
            std::cout << "Product: " << sale.first << ", Revenue: $" << sale.second << std::endl;
            totalRevenue += sale.second;
            if (sale.second > maxSales) {
                maxSales = sale.second;
                bestSellingProduct = sale.first;
            }
        }

        std::cout << "Total Revenue: $" << totalRevenue << std::endl;
        std::cout << "Best Selling Product: " << bestSellingProduct << std::endl;
    }
};

int main() {
    // Create a shop
    Shop rmitShop("RMIT COSC2082 STORE");

    // Add products to the shop
    rmitShop.addOrUpdateProduct(Product("Laptop", 1000.0, 10));
    rmitShop.addOrUpdateProduct(Product("Keyboard", 150.0, 20));
    rmitShop.addOrUpdateProduct(Product("Mouse", 20.0, 150));
    rmitShop.addOrUpdateProduct(Product("Monitor", 500.0, 10));

    // Add customers
    rmitShop.addCustomer(Customer("Minh Phan"));
    rmitShop.addCustomer(Customer("Lam Do"));
    rmitShop.addCustomer(Customer("Phuc Hoang"));

    // Purchase by Minh Phan
    std::map<std::string, int> minhPurchase = {{"Laptop", 1}, {"Keyboard", 2}};
    rmitShop.printBill("Minh Phan", minhPurchase);

    std::cout << "\n";

    // Ppurchase by Lam Do
    std::map<std::string, int> lamPurchase = {{"Monitor", 3}};
    rmitShop.printBill("Lam Do", lamPurchase);

    std::cout << "\n";

    // Purchase by Phuc Hoang
    std::map<std::string, int> phucPurchase = {{"Mouse", 100}};
    rmitShop.printBill("Phuc Hoang", phucPurchase);

    std::cout << "\n";

    // Generate sales report
    // Mouse is expected to be the best selling (assume that best selling product is calculated by revenue)
    rmitShop.generateSaleReport();

    return 0;
}
