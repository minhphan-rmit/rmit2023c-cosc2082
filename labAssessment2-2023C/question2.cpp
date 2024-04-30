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
#include <string>

class City {
public:
    std::string name;
    int stayingDays;
    City* nextCity;

    City(std::string cityName, int days) : name(cityName), stayingDays(days), nextCity(nullptr) {}
};

class CityList {
public:
    City* head;

    CityList() : head(nullptr) {}

    void addCity(std::string name, int days) {
        City* newCity = new City(name, days);
        if (head == nullptr) {
            head = newCity;
            return;
        }

        City* temp = head;
        while (temp->nextCity != nullptr) {
            temp = temp->nextCity;
        }
        temp->nextCity = newCity;
    }

    void printTripPlan() {
        City* temp = head;
        while (temp != nullptr) {
            std::cout << "• " << temp->name << ": " << temp->stayingDays << " days\n";
            temp = temp->nextCity;
        }
    }

    void updateTripPlan(std::string cityName, int newDays) {
        City* temp = head;
        City* prev = nullptr;
        while (temp != nullptr) {
            if (temp->name == cityName) {
                if (newDays == 0) {
                    // Remove city from the list
                    if (prev != nullptr) {
                        prev->nextCity = temp->nextCity;
                    } else {
                        head = temp->nextCity;
                    }
                    delete temp;
                    temp = nullptr;
                    std::cout << "> Removed from the trip plan. ";
                } else {
                    temp->stayingDays = newDays;
                    std::cout << "> Updated. ";
                }
                break;
            }
            prev = temp;
            temp = temp->nextCity;
        }

        int removedDays;
        if (newDays == 0) {
            removedDays = temp->stayingDays;
        }

        // Calculate total days from this city to end
        int totalDays = 0;
        while (temp != nullptr) {
            totalDays += temp->stayingDays;
            temp = temp->nextCity;
        }

        if (newDays == 0) {
            std::cout << "There will be a total of " << totalDays - removedDays << " days staying in the next cities in the trip.\n";
        } else {
            std::cout << "There will be a total of " << totalDays << " days staying in this and next cities in the trip.\n";
        }
    }

    void promptForUpdate() {
        std::string cityName;
        int days;
        std::cout << "Enter the City's name: ";
        std::cin.ignore(1, '\n');
        getline(std::cin, cityName);

        std::cout <<"Update the number of staying days: ";
        std::cin >> days;

        updateTripPlan(cityName, days);
        std::cin.clear();
    }
};

int main() {
    // Initalization of trip plan
    CityList tripPlan;
    tripPlan.addCity("Hue", 5);
    tripPlan.addCity("Da Nang", 3);
    tripPlan.addCity("Nha Trang", 4);
    tripPlan.addCity("Da Lat", 2);
    tripPlan.addCity("Can Tho", 3);

    // Print initial trip plan
    std::cout << "Initial Trip Plan:\n";
    tripPlan.printTripPlan();
    std::cout << std::endl;

    // Test updating Nha Trang to 5 staying days
    tripPlan.promptForUpdate();
    std::cout << "\nUpdated Trip Plan:\n";
    tripPlan.printTripPlan();

    // Testing removing Da Lat from the trip
    tripPlan.promptForUpdate();
    std::cout << "\nUpdated Trip Plan:\n";
    tripPlan.printTripPlan();

    return 0;
}
