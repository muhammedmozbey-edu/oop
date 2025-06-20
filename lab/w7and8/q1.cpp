#include <iostream>
#include <vector>
using namespace std;

class Citizen {
private:
    string name;
    int id;
public:
    Citizen(string n, int i) : name(n), id(i) {}

    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    void displayInfo() const {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};

class Car {
private:
    string licensePlate;
    string model;
public:
    Car(string licensePlate, string model) : licensePlate(licensePlate), model(model) {}
    void display() const {
        cout << "Car License Plate: " << licensePlate << ", Model: " << model << endl;
    }
};

class PoliceOfficer {
private:
    string name;
    int badgeNumber;
public:
    PoliceOfficer(string n, int b) : name(n), badgeNumber(b) {} 
    void displayInfo() const {
        cout << "Officer Name: " << name << ", Badge Number: " << badgeNumber << endl;
    }
};

class Ticket {
private:
    Citizen citizen;
    Car car;
    PoliceOfficer officer;
    double fineAmount;
public:
    Ticket(Citizen c, Car ca, PoliceOfficer o, double fine) : citizen(c), car(ca), officer(o), fineAmount(fine) {}  
    void displayTicketInfo() const {
        cout << "Ticket Information:" << endl;
        citizen.displayInfo();
        car.display();
        officer.displayInfo();
        cout << "Fine Amount: $" << fineAmount << endl;
    }
};

int main() {
    PoliceOfficer officer ("Jane Smith", 12345);
    Citizen driver ("John Doe", 67890);
    Car car("34ABC123", "Toyota Corolla");

    Ticket ticket(driver, car, officer, 150.0);
    ticket.displayTicketInfo();

    return 0;
}