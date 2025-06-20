#include <iostream>
#include <string>
using namespace std;

// Customer class to represent a customer with a balance
class Customer {
private:
    string name;
    double balance;

public:
    // Constructor
    Customer(string customerName, double initialBalance) {
        name = customerName;
        balance = initialBalance;
    }
    
    // Getter methods
    string getName() const {
        return name;
    }
    
    double getBalance() const {
        return balance;
    }
    
    // Method to decrease balance
    void decreaseBalance(double amount) {
        if (amount > balance) {
            cout << "Warning: " << name << " doesn't have enough balance!" << endl;
        } else {
            balance -= amount;
            cout << name << "'s balance decreased by $" << amount << endl;
        }
    }
    
    // Display customer information
    void displayInfo() const {
        cout << "Customer: " << name << ", Balance: $" << balance << endl;
    }
};

// Salesman class with different sell methods
class Salesman {
private:
    string name;
    double salesTotal;

public:
    // Constructor
    Salesman(string salesmanName) {
        name = salesmanName;
        salesTotal = 0.0;
    }
    
    // Sell method that takes Customer by value (creates a copy)
    void sellByValue(Customer customer, double amount) {
        cout << "\n--- Selling by Value ---" << endl;
        cout << "Before sale - ";
        customer.displayInfo();
        
        customer.decreaseBalance(amount);
        salesTotal += amount;
        
        cout << "After sale - ";
        customer.displayInfo();
        cout << name << " made a sale of $" << amount << endl;
        cout << "Total sales: $" << salesTotal << endl;
        cout << "(Note: The original customer object remains unchanged)" << endl;
    }
    
    // Sell method that takes Customer by reference
    void sellByReference(Customer& customer, double amount) {
        cout << "\n--- Selling by Reference ---" << endl;
        cout << "Before sale - ";
        customer.displayInfo();
        
        customer.decreaseBalance(amount);
        salesTotal += amount;
        
        cout << "After sale - ";
        customer.displayInfo();
        cout << name << " made a sale of $" << amount << endl;
        cout << "Total sales: $" << salesTotal << endl;
        cout << "(Note: The original customer object was modified)" << endl;
    }
    
    // Display salesman information
    void displayInfo() const {
        cout << "Salesman: " << name << ", Total Sales: $" << salesTotal << endl;
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 15:00:01" << endl;
    cout << "User: muhammedmozbey-edu" << endl;
    
    // Create a customer
    Customer john("John Smith", 100.0);
    
    // Create a salesman
    Salesman bob("Bob Johnson");
    
    // Display initial information
    cout << "Initial state:" << endl;
    john.displayInfo();
    bob.displayInfo();
    
    // Demonstrate sell by value (creates a copy, original remains unchanged)
    bob.sellByValue(john, 50.0);
    cout << "\nOriginal customer after sell by value: " << endl;
    john.displayInfo();  // Balance should still be 100.0
    
    // Demonstrate sell by reference (modifies the original)
    bob.sellByReference(john, 50.0);
    cout << "\nOriginal customer after sell by reference: " << endl;
    john.displayInfo();  // Balance should now be 50.0
    
    return 0;
}