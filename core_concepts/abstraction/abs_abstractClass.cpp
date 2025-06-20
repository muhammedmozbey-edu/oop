#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Abstract base class
class Vehicle {
protected:
    string brand;
    
public:
    Vehicle(string b) : brand(b) {}
    
    // Pure virtual functions - must be implemented by derived classes
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual double getFuelEfficiency() = 0;
    
    // Regular virtual function - can be overridden
    virtual void honk() {
        cout << brand << " vehicle honks!" << endl;
    }
    
    // Non-virtual function - common to all vehicles
    void displayBrand() {
        cout << "Brand: " << brand << endl;
    }
    
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
    Car(string brand) : Vehicle(brand) {}
    
    void start() override {
        cout << brand << " car engine started" << endl;
    }
    
    void stop() override {
        cout << brand << " car engine stopped" << endl;
    }
    
    double getFuelEfficiency() override {
        return 25.5;  // Miles per gallon
    }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(string brand) : Vehicle(brand) {}
    
    void start() override {
        cout << brand << " motorcycle engine roared to life" << endl;
    }
    
    void stop() override {
        cout << brand << " motorcycle engine turned off" << endl;
    }
    
    double getFuelEfficiency() override {
        return 45.0;  // Miles per gallon
    }
    
    void honk() override {
        cout << brand << " motorcycle beeps!" << endl;
    }
};

void operateVehicle(Vehicle& vehicle) {
    vehicle.displayBrand();
    vehicle.start();
    vehicle.honk();
    cout << "Fuel efficiency: " << vehicle.getFuelEfficiency() << " MPG" << endl;
    vehicle.stop();
    cout << "---" << endl;
}

int main() {
    // Vehicle v("Generic");  // ERROR! Cannot instantiate abstract class
    
    Car car("Toyota");
    Motorcycle bike("Harley");
    
    operateVehicle(car);
    operateVehicle(bike);
    
    // Polymorphic container
    vector<unique_ptr<Vehicle>> garage;
    garage.push_back(make_unique<Car>("Honda"));
    garage.push_back(make_unique<Motorcycle>("Yamaha"));
    
    cout << "Operating all vehicles in garage:" << endl;
    for (auto& vehicle : garage) {
        operateVehicle(*vehicle);
    }
    
    return 0;
}