#include <iostream>
using namespace std;

class Base {
protected:
    int baseValue;
    
public:
    Base(int val) : baseValue(val) {
        cout << "Base constructor called with: " << val << endl;
    }

};

class Derived : public Base {
private:
    int derivedValue;
    
public:
    Derived(int baseVal, int derivedVal) 
        : Base(baseVal), derivedValue(derivedVal) {  // Constructor chaining
        cout << "Derived constructor called with: " << derivedVal << endl;
    }
    
    void display() {
        cout << "Base: " << baseValue << ", Derived: " << derivedValue << endl;
    }
};

int main() {
    cout << "Creating derived object:" << endl;
    Derived d(10, 20);
    d.display();
    
    cout << "\nObject going out of scope:" << endl;
    return 0;
}