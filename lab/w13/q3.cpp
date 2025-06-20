#include <iostream>
#include <string>
using namespace std;

// Base class
class Flower {
public:
    // Virtual method to be overridden
    virtual string getCareAdvice() const {
        return "General flower care advice.";
    }

    // Virtual destructor (good practice for polymorphism)
    virtual ~Flower() {}
};

// Derived class Rose
class Rose : public Flower {
public:
    string getCareAdvice() const override {
        return "Roses need full sun and regular watering.";
    }
};

// Derived class Tulip
class Tulip : public Flower {
public:
    string getCareAdvice() const override {
        return "Tulips prefer cool weather and well-drained soil.";
    }
};

// Function to print care advice
void printCareAdvice(Flower* flower) {
    // Polymorphic call to getCareAdvice
    cout << "Care Advice: " << flower->getCareAdvice() << endl;
}

int main() {
    Rose rose;
    Tulip tulip;

    // Base class pointers
    Flower* f1 = &rose;
    Flower* f2 = &tulip;

    cout << "Rose -> ";
    printCareAdvice(f1);  // Calls Rose::getCareAdvice()

    cout << "Tulip -> ";
    printCareAdvice(f2);  // Calls Tulip::getCareAdvice()

    return 0;
}
