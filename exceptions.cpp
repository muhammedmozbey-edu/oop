#include <iostream>
#include <stdexcept>
using namespace std;

// Function that might throw an exception
double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Division by zero!");  // Throwing an exception
    }
    return a / b;
}

int main() {
    try {
        // Code that might throw an exception
        cout << "10 / 2 = " << divide(10, 2) << endl;  // Works fine
        cout << "10 / 0 = " << divide(10, 0) << endl;  // Will throw exception
        cout << "This line will never execute" << endl;
    }
    catch (const runtime_error e) {
        // Handle the exception
        cout << "Error caught: " << e.what() << endl;
    }
    
    cout << "Program continues after exception handling" << endl;
    return 0;
}