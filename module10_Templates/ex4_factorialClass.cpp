// Exercise 4: Class Template
// Develop a class template that can be used to compute 
// the factorial of an integer value as below:

// template<int N> class factorial;
// The class template should provide a single (public) 

// member value that holds the factorial of N.
// Template specialization should be used to handle the case of N equal to 0

//N: non-type argument of the template   
// (we will pass in an integer value later)
//N = 4 --> 4!  = 1*2*3*4


#include <iostream>
using std::cout;

template <int N>    
class factorial {
public:
    const static int value = N * factorial<N - 1>::value; //static attribute
};

//template specification here (for the case N == 0)
template <>    
class factorial<0> {
public:
    const static int value = 1; //static attribute
};


int main(){
    //create an object
    cout << factorial<0>::value << "\n";
    cout << factorial<3>::value << "\n";

    return 1;
}