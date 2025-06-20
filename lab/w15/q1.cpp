#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class SmartDevice {
public:
    // Pure virtual function - makes this class abstract
    virtual void turnOn() = 0;
    
    // Virtual destructor
    virtual ~SmartDevice() {}
};

// Derived class: SmartLight
class SmartLight : public SmartDevice {
public:
    // Implementation of the pure virtual function
    void turnOn() override {
        cout << "Smart Light: Turning on with soft white light" << endl;
    }
};

// Derived class: SmartSpeaker
class SmartSpeaker : public SmartDevice {
public:
    // Implementation of the pure virtual function
    void turnOn() override {
        cout << "Smart Speaker: Powering on and playing welcome sound" << endl;
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 16:30:59" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    cout << "\n--- Smart Home Device Control System ---" << endl;
    
    // Create objects of the derived classes
    SmartLight light;
    SmartSpeaker speaker;
    
    // Call turnOn() for each device
    cout << "\nActivating devices:" << endl;
    light.turnOn();
    speaker.turnOn();
    
    // Using polymorphism with base class pointers
    cout << "\nActivating devices through base class pointers:" << endl;
    SmartDevice* devices[2];
    devices[0] = &light;
    devices[1] = &speaker;
    
    for (int i = 0; i < 2; i++) {
        devices[i]->turnOn();
    }
    
    return 0;
}