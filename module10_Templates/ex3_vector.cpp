#include <iostream>
#include <vector>
using std::cout;
using std::vector;

template <typename genericType>
class MyClass {
private:
    vector<genericType> vectList; //attribute

public:
    MyClass(vector<genericType> vectListVal ) //constructor
    : vectList(vectListVal){}

    bool remove(genericType element){
        for (int i = 0; i < vectList.size(); i++){
            if (vectList[i] == element){
                vectList.erase( vectList.begin() + i);
                return true; 
            }
        }

        std::cerr << "The element is not found in the list \n";
        return false;
    }

    bool insert(genericType element){
        for (int i = 0; i < vectList.size(); i++){
            if (vectList[i] == element){
                std::cerr << "The element is already in the list \n";
                return false;
            }
        }

        vectList.push_back(element);
        return true;
    }

    void showValues(){
        for (genericType element: vectList){
            cout << element << " ";
        }
        cout << "\n";
    }

};


int main(){
    MyClass<int> intList( {1, 5, 7, 10} );
    intList.insert(20);
    intList.remove(7);
    intList.showValues();

    MyClass<std::string> stringList( {"Hello", "Hi", "Ciao"} );
    stringList.insert("XinChao");
    stringList.remove("Hi");
    stringList.showValues();


    return 0;
}