#include <iostream>
#include <string>
using namespace std;

// Base class: Vehicle
class Vehicle {
protected:
    string id;
    string brand;
    string model;
    int year;
    double price;
    string color;
    
public:
    // Constructor
    Vehicle(string vehicleId, string vehicleBrand, string vehicleModel, 
            int vehicleYear, double vehiclePrice, string vehicleColor) 
        : id(vehicleId), brand(vehicleBrand), model(vehicleModel), 
          year(vehicleYear), price(vehiclePrice), color(vehicleColor) {
    }
    
    // Display vehicle information
    void display() const {
        cout << year << " " << brand << " " << model << endl;
        cout << "Color: " << color << endl;
        cout << "Price: $" << price << endl;
    }
};

// Derived class: Car
class Car : public Vehicle {
private:
    int numDoors;
    string fuelType;
    
public:
    // Constructor
    Car(string id, string brand, string model, int year, double price, string color,
        int doors, string fuel) 
        : Vehicle(id, brand, model, year, price, color), 
          numDoors(doors), fuelType(fuel) {
    }
    
    // Override display method
    void display() const {
        cout << "\n--- CAR LISTING ---" << endl;
        Vehicle::display(); // Call base class method
        cout << "Doors: " << numDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// Derived class: Motorcycle
class Motorcycle : public Vehicle {
private:
    int engineSize; // cc
    string type;    // sport, cruiser, etc.
    
public:
    // Constructor
    Motorcycle(string id, string brand, string model, int year, double price, string color,
               int cc, string bikeType) 
        : Vehicle(id, brand, model, year, price, color), 
          engineSize(cc), type(bikeType) {
    }
    
    // Override display method
    void display() const {
        cout << "\n--- MOTORCYCLE LISTING ---" << endl;
        Vehicle::display(); // Call base class method
        cout << "Engine: " << engineSize << "cc" << endl;
        cout << "Type: " << type << endl;
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 16:09:40" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    cout << "\nVEHICLE SALES WEBSITE LISTINGS" << endl;
    cout << "==============================" << endl;
    
    // Create car objects
    Car car1("C001", "Toyota", "Camry", 2024, 28500, "Silver", 4, "Hybrid");
    Car car2("C002", "Honda", "Civic", 2025, 24000, "Blue", 4, "Gasoline");
    
    // Create motorcycle objects
    Motorcycle bike1("M001", "Harley-Davidson", "Street Glide", 2025, 21000, "Black", 1868, "Cruiser");
    Motorcycle bike2("M002", "Kawasaki", "Ninja", 2024, 12000, "Green", 1000, "Sport");
    
    // Display all vehicles
    car1.display();
    car2.display();
    bike1.display();
    bike2.display();
    
    return 0;
}
