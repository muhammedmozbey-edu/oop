#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;        // Hidden data
    string accountNumber;  // Hidden data
    
public:
    // Constructor
    BankAccount(string accNum, double initialBalance) 
        : accountNumber(accNum), balance(initialBalance) {}
    
    // Controlled access methods
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
            return true;
        }
        cout << "Insufficient funds!" << endl;
        return false;
    }
    
    // Read-only access
    double getBalance() const { return balance; }
    string getAccountNumber() const { return accountNumber; }
};

int main() {
    BankAccount account("12345", 1000.0);
    
    // account.balance = 5000;  // ERROR! Cannot access private member
    
    account.deposit(500);
    account.withdraw(200);
    cout << "Balance: $" << account.getBalance() << endl;
    
    return 0;
}