#include <iostream>
using std::cout;
using std::string;

class Cat {
public:
    string name;
    int age;

    //Default constructor with default arguments
    Cat (std::string nameVal = "", int ageVal = 0)
        : name(nameVal), age(ageVal) {};
};



class Person {
public:
    Cat cat; //attribute is an object
    string name;

    //**** Default constructor with default arguments
    Person (Cat mycat = Cat(), string nameVal = "")
        :cat(mycat), name(nameVal) {};
};



int main() {
    
    Person personArr[3] = { Person(Cat("Cat1", 3), "An"),
                            Person(Cat("Cat2", 5), "Tae-hee"),
                            Person(Cat("Cat3", 4), "Viet")};

    Person maxPerson = personArr[0]; //assume person 0 is the one that has the oldest cat
    for (int i = 1; i <= 2; i++) { //compare the cat's age with that of other people's cats
        if (maxPerson.cat.age < personArr[i].cat.age) {
            maxPerson = personArr[i];
        }
    }

    std::cout   << "Person with oldest cat: \n"
                << "Person Name = " << maxPerson.name
                << ", Cat Name = " << maxPerson.cat.name
                << ", Cat Age = " << maxPerson.cat.age;

    return 0;
}