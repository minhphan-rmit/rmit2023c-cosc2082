#include <iostream>
using std::cout;
using std::string;

class Broker {
private:
    string name;
    int buyPrice;
    Broker *nextBuyer;

public:
    //constructor
    Broker(string name = "", int buyPrice = 0)
        : name(name), buyPrice(buyPrice) {}

    //function to set connection
    void setNextBuyer(Broker *next) { nextBuyer = next; }

    friend void showFordLinks(Broker *head);
    friend void minProfits(Broker *head);
};

// Qa
void showFordLinks(Broker *head) {
    Broker *temp = head; // temp is current node

    while (temp != nullptr) {
        // print out current broker's name and buy price
        if (temp == head) {
            cout << temp->name << " : "
                 << "initially bought the house for $" << temp->buyPrice << "\n";
        } else {
            cout << temp->name << " : "
                 << "price = $" << temp->buyPrice << "\n";
        }

        // print out the current broker's name (for next node)
        if (temp->nextBuyer != nullptr) {
            cout << temp->name << " --> ";
        }

        temp = temp->nextBuyer; // go to the next node
    }

    cout << "\n";
}



// Qb
void minProfits(Broker *head) {
    Broker *temp = head; // temp is the current node

    // Assume that the first broker has lowest profit
    int minProfit = (temp->nextBuyer)->buyPrice - temp->buyPrice; //profit of first broker
    Broker *minBroker = head;

    // Check with other broker
    while (temp != nullptr) {
        if (temp->nextBuyer != nullptr) { //already sold the house
            //Caculate and compare profit
            int profit = (temp->nextBuyer)->buyPrice - temp->buyPrice;
            if (profit < minProfit) {
                minProfit = profit;
                minBroker = temp;
            }
        } 
        temp = temp->nextBuyer; // go the next node
    }
  
    if (minBroker != nullptr) {
        cout << "\nThe broker with max profit: \n"
                << "> name: " << minBroker->name << "\n> profit: " << minProfit
                << "\n\n";
    }
}


int main() {
    // create nodes
    Broker broker1("David", 800), broker2("John", 1000), broker3("Peter", 1200),
    broker4("Luna", 1800), broker5("Sophia", 3500);

    // link nodes
    Broker *head = &broker1; // pointer variable
    broker1.setNextBuyer(&broker2);
    broker2.setNextBuyer(&broker3);
    broker3.setNextBuyer(&broker4);
    broker4.setNextBuyer(&broker5);
    broker5.setNextBuyer(nullptr);
    Broker *tail = &broker5; // pointer variable

    // Qa. show links
    showFordLinks(head);

    // Qb. show brokers with min profit
    minProfits(head);

    return 0;
}