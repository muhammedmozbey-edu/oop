#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) : balance(b) {}

    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return true;
        }
        return false;
    }
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
    double getBalance() const {
        return balance;
    }
    void displayBalance() const {
        cout << "Current Balance: $" << balance << endl;
    }
};  

int main() {
    // Create a bank account with initial balance of $1000
    BankAccount myAccount(1000);
    
    // Display initial balance
    cout << "Initial ";
    myAccount.displayBalance();
    
    // Test deposit function
    cout << "\nTesting deposit functionality:" << endl;
    myAccount.deposit(500);
    myAccount.deposit(-100);  // Should show error
    myAccount.displayBalance();
    
    // Test withdraw function
    cout << "\nTesting withdraw functionality:" << endl;
    myAccount.withdraw(300);
    myAccount.withdraw(-50);   // Should show error
    myAccount.withdraw(2000);  // Should show error - insufficient funds
    myAccount.displayBalance();
    
    return 0;
}