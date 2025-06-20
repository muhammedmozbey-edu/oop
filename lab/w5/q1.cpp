#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    string model;
    int km;
    bool isManuel;
    bool isUsed;
public:
    // Default constructor
    Car() {
        brand = "Unknown";
        model = "Unknown";
        km = 0;
        isManuel = false;
        isUsed = false; 
    }

    // Constructor taking all attributes
    Car(string b, string m, int k, bool manuel, bool used) 
        : brand(b), model(m), km(k), isManuel(manuel), isUsed(used) {}

    // Constructor taking only brand and model
    Car(string b, string m) 
        : brand(b), model(m), km(0), isManuel(false), isUsed(false) {}

    void displayInfo() const {
        cout << "Car Brand: " << brand << endl;
        cout << "Car Model: " << model << endl;
        cout << "Kilometers Driven: " << km << endl;
        cout << "Is Manual: " << (isManuel ? "Yes" : "No") << endl;
        cout << "Is Used: " << (isUsed ? "Yes" : "No") << endl;
    }

};

int main() {
    // Using the default constructor
    Car car1;
    car1.displayInfo();
    cout << endl;

    // Using the constructor with all attributes
    Car car2("Toyota", "Corolla", 15000, true, false);
    car2.displayInfo();
    cout << endl;

    // Using the constructor with only brand and model
    Car car3("Honda", "Civic");
    car3.displayInfo();

    return 0;
}