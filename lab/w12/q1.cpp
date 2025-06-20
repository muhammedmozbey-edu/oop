#include <iostream>
#include <string>
using namespace std;

// Base class: Bill
class Bill {
protected:
    double billAmount;
    string date;
    string billNumber;
    
public:
    // Constructor
    Bill(string billNum, string billDate, double amount) 
        : billNumber(billNum), date(billDate), billAmount(amount) {
    }
    
    // Display bill information
    void display() const {
        cout << "Bill Number: " << billNumber << endl;
        cout << "Date: " << date << endl;
        cout << "Amount: $" << billAmount << endl;
    }
};

// Derived class: PhoneBill
class PhoneBill : public Bill {
private:
    int minutesSpoken;
    double internetUsed; // in GB
    
public:
    // Constructor
    PhoneBill(string billNum, string billDate, double amount, 
              int minutes, double internet) 
        : Bill(billNum, billDate, amount),
          minutesSpoken(minutes), internetUsed(internet) {
    }
    
    // Override display method
    void display() const {
        Bill::display(); // Call base class method
        cout << "Minutes Used: " << minutesSpoken << " minutes" << endl;
        cout << "Internet Used: " << internetUsed << " GB" << endl;
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 16:08:13" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    // Create a regular bill
    Bill electricityBill("E12345", "2025-06-15", 124.50);
    
    // Create a phone bill
    PhoneBill myPhoneBill("P67890", "2025-06-18", 75.50, 320, 4.5);
    
    // Display the bills
    cout << "\n--- Regular Bill ---" << endl;
    electricityBill.display();
    
    cout << "\n--- Phone Bill ---" << endl;
    myPhoneBill.display();
    
    return 0;
}