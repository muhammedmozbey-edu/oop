/*
Constructors are special methods that run automatically when an object is created. 
Think of them as the "birth certificate" process for objects 
- they ensure every object starts life in a valid, well-defined state.
*/

#include <iostream>
using namespace std;

class Car {
private:
    string m_brand;
    string m_model;
    bool m_isUsed;
    int m_km;
    bool m_isManual;
    
public:
    // Default constructor - creates a "generic" car
    Car() : m_brand{"Unknown"}, m_model{"Unknown"}, m_isUsed{false}, m_km{0}, m_isManual{true} {
        cout << "Default constructor called\n";
    }
    
    // Constructor with all parameters - complete specification
    Car(const string& brand, const string& model, bool used, int km, bool manual)
        : m_brand{brand}, m_model{model}, m_isUsed{used}, m_km{km}, m_isManual{manual} {
        cout << "Full constructor called\n";
    }
    
    // Constructor without km - defaults to 0 (useful for new cars)
    Car(const string& brand, const string& model, bool manual)
        : m_brand{brand}, m_model{model}, m_isUsed{false}, m_km{0}, m_isManual{manual} {
        cout << "Constructor without km called\n";
    }
};

/*
class Car {
public:
    // One constructor that can serve multiple purposes
    Car(const string& brand = "Unknown", 
        const string& model = "Unknown", 
        bool used = false, 
        bool manual = true)  // Default values as specified
        : m_brand{brand}, m_model{model}, m_isUsed{used}, m_km{0}, m_isManual{manual} {}
};

// Now you can create cars in multiple ways:
Car defaultCar;                           // All defaults
Car brandOnly{"Toyota"};                  // Brand specified, rest default
Car specificCar{"Honda", "Civic", true, false};  // All specified
*/