#include <iostream>
#include <string>
using namespace std;

// Base class
class Guest {
public:
    virtual string getName() const {
        return "Guest";
    }
};

// Derived class with incorrect method name
class VIPGuest : public Guest {
public:
    // Notice the capital 'G' - this is NOT overriding the base class method
    string GetName() const {
        return "VIP Guest";
    }
};

// Corrected version with override keyword
class CorrectedVIPGuest : public Guest {
public:
    // Now with override keyword - compiler will check if this truly overrides
    string getName() const override {
        return "Corrected VIP Guest";
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 16:26:07" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    cout << "\n--- Q2: What does 'override' change? ---" << endl;
    
    // Create a VIPGuest and point to it with a Guest pointer
    VIPGuest vip;
    Guest* guestPtr = &vip;
    
    cout << "Calling getName() via base pointer to VIPGuest:" << endl;
    cout << guestPtr->getName() << endl;  // This calls Guest::getName()
    
    cout << "\nDirect call to VIPGuest::GetName():" << endl;
    cout << vip.GetName() << endl;        // This calls VIPGuest::GetName()
    
    // Now with the corrected version
    CorrectedVIPGuest correctedVip;
    Guest* correctedPtr = &correctedVip;
    
    cout << "\nCalling getName() via base pointer to CorrectedVIPGuest:" << endl;
    cout << correctedPtr->getName() << endl;  // This calls CorrectedVIPGuest::getName()
    
    return 0;
}