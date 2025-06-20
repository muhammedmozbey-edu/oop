#include <iostream>
#include <string>
using namespace std;

// Base class
class AdminPanel {
public:
    virtual void login() {
        cout << "AdminPanel login: Standard admin login" << endl;
    }
};

// Derived class with final method
class SuperAdminPanel : public AdminPanel {
public:
    void login() final override {
        cout << "SuperAdminPanel login: Enhanced security login" << endl;
    }
};

// This class attempts to override a final method
// Uncommenting this code would cause a compilation error
/*
class HackedPanel : public SuperAdminPanel {
public:
    // Error: cannot override 'final' method
    void login() override {
        cout << "HackedPanel login: Bypassed security" << endl;
    }
};
*/

// Making an entire class final
class FinalClass final {
public:
    void someMethod() {
        cout << "This is a method in a final class" << endl;
    }
};

// Uncommenting this code would cause a compilation error
/*
class DerivedFromFinal : public FinalClass {
public:
    void anotherMethod() {
        cout << "This class cannot be created" << endl;
    }
};
*/

int main() {
    cout << "Current Date and Time: 2025-06-19 16:26:07" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    cout << "\n--- Q3: What does the 'final' keyword change? ---" << endl;
    
    AdminPanel admin;
    SuperAdminPanel superAdmin;
    
    cout << "Calling login() on AdminPanel:" << endl;
    admin.login();
    
    cout << "\nCalling login() on SuperAdminPanel:" << endl;
    superAdmin.login();
    
    cout << "\nNote: Attempting to override a final method causes a compilation error." << endl;
    cout << "Similarly, attempting to inherit from a final class causes a compilation error." << endl;
    
    return 0;
}