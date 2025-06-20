#include <iostream>
using namespace std;

class Calculator {
public:
    // Function overloading - same name, different parameters
    int add(int a, int b) {
        cout << "Adding integers: ";
        return a + b;
    }
    
    double add(double a, double b) {
        cout << "Adding doubles: ";
        return a + b;
    }
    
    int add(int a, int b, int c) {
        cout << "Adding three integers: ";
        return a + b + c;
    }
    
    // Operator overloading
    Calculator operator+(const Calculator& other) {
        cout << "Calculator addition operator called" << endl;
        return Calculator();
    }
};

int main() {
    Calculator calc;
    
    cout << calc.add(5, 10) << endl;           // Calls int version
    cout << calc.add(3.14, 2.86) << endl;     // Calls double version
    cout << calc.add(1, 2, 3) << endl;        // Calls three-parameter version
    
    Calculator calc1, calc2;
    Calculator result = calc1 + calc2;         // Operator overloading
    
    return 0;
}