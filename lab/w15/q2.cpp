#include <iostream>
#include <string>
using namespace std;

// First abstract class (interface)
class Eatable {
public:
    // Pure virtual function
    virtual void eat() = 0;
    
    // Virtual destructor
    virtual ~Eatable() {}
};

// Second abstract class (interface)
class Resizable {
public:
    // Pure virtual function
    virtual void resize() = 0;
    
    // Virtual destructor
    virtual ~Resizable() {}
};

// Concrete class implementing both interfaces
class VirtualBurger : public Eatable, public Resizable {
public:
    // Implementation of eat() from Eatable
    void eat() override {
        cout << "Virtual Burger: Being eaten! Yum!" << endl;
    }
    
    // Implementation of resize() from Resizable
    void resize() override {
        cout << "Virtual Burger: Resizing to a bigger/smaller burger" << endl;
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 16:32:03" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    cout << "\n--- Virtual Reality Simulation ---" << endl;
    
    // Create a VirtualBurger object
    VirtualBurger burger;
    
    // Call both methods
    cout << "Interacting with burger directly:" << endl;
    burger.eat();
    burger.resize();
    
    // Demonstrate polymorphism with base class pointers
    Eatable* eatableItem = &burger;
    Resizable* resizableItem = &burger;
    
    cout << "\nInteracting through interface pointers:" << endl;
    eatableItem->eat();
    resizableItem->resize();
    
    return 0;
}