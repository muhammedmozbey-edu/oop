#include <iostream>
#include <string>
using namespace std;

// Enum for workplace types
enum class WorkplaceType {
    CAFE,
    GAS_STATION,
    STUDIO
};

// Function to convert enum to string
string workplaceTypeToString(WorkplaceType type) {
    switch(type) {
        case WorkplaceType::CAFE:
            return "Cafe";
        case WorkplaceType::GAS_STATION:
            return "Gas Station";
        case WorkplaceType::STUDIO:
            return "Studio";
        default:
            return "Unknown";
    }
}

// Base class: RealEstate
class RealEstate {
protected:
    string id;
    double price;
    double area; // square meters
    string location;
    
public:
    // Constructor
    RealEstate(string propertyId, double propertyPrice, double propertyArea, string propertyLocation) 
        : id(propertyId), price(propertyPrice), area(propertyArea), location(propertyLocation) {
    }
    
    // Display method
    virtual void display() const {
        cout << "ID: " << id << endl;
        cout << "Location: " << location << endl;
        cout << "Area: " << area << " square meters" << endl;
        cout << "Price: $" << price << endl;
    }
};

// House subclass
class House : public RealEstate {
private:
    bool isFurnished;
    int numRooms;
    
public:
    // Constructor
    House(string id, double price, double area, string location, bool furnished, int rooms)
        : RealEstate(id, price, area, location), isFurnished(furnished), numRooms(rooms) {
    }
    
    // Display method
    void display() const override {
        cout << "\n--- HOUSE LISTING ---" << endl;
        RealEstate::display();
        cout << "Rooms: " << numRooms << endl;
        cout << "Furnished: " << (isFurnished ? "Yes" : "No") << endl;
    }
};

// Land subclass
class Land : public RealEstate {
private:
    bool isDevelopable;
    
public:
    // Constructor
    Land(string id, double price, double area, string location, bool developable)
        : RealEstate(id, price, area, location), isDevelopable(developable) {
    }
    
    // Display method
    void display() const override {
        cout << "\n--- LAND LISTING ---" << endl;
        RealEstate::display();
        cout << "Developable: " << (isDevelopable ? "Yes" : "No") << endl;
    }
};

// Workplace subclass
class Workplace : public RealEstate {
private:
    WorkplaceType type;
    
public:
    // Constructor
    Workplace(string id, double price, double area, string location, WorkplaceType workplaceType)
        : RealEstate(id, price, area, location), type(workplaceType) {
    }
    
    // Display method
    void display() const override {
        cout << "\n--- WORKPLACE LISTING ---" << endl;
        RealEstate::display();
        cout << "Type: " << workplaceTypeToString(type) << endl;
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 16:12:56" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    cout << "\nREAL ESTATE LISTINGS" << endl;
    cout << "====================" << endl;
    
    // Create house objects
    House house1("H001", 450000, 180, "123 Oak Street, Springfield", true, 4);
    House house2("H002", 320000, 120, "456 Pine Avenue, Riverdale", false, 3);
    
    // Create land objects
    Land land1("L001", 120000, 5000, "Rural Route 7, County Line", true);
    Land land2("L002", 75000, 2500, "Lakeview Heights, Plot 12", false);
    
    // Create workplace objects
    Workplace workplace1("W001", 380000, 150, "Downtown Main Street", WorkplaceType::CAFE);
    Workplace workplace2("W002", 560000, 200, "Highway 101 Exit 25", WorkplaceType::GAS_STATION);
    Workplace workplace3("W003", 420000, 180, "Arts District, Building C", WorkplaceType::STUDIO);
    
    // Display all properties
    house1.display();
    house2.display();
    land1.display();
    land2.display();
    workplace1.display();
    workplace2.display();
    workplace3.display();
    
    return 0;
}