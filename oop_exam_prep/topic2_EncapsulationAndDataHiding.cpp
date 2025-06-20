/*
This is where we get to one of the most important principles in OOP. 
Let me ask you a thinking question: 
Why shouldn't every part of your program be able to directly access and modify every piece of data?

private: Only the class itself can access (like the balance in our bank account)
public: Anyone can access (like the methods customers can use)
protected: The class and its children can access (we'll see this with inheritance)
*/

#include <iostream>
using namespace std;

class BankAccount {
private:
    double m_balance;  // Hidden from outside access
    
public:
    BankAccount(double initialBalance) : m_balance{initialBalance} {}
    
    // Controlled access through methods
    bool withdraw(double amount) {
        if (amount > 0 && amount <= m_balance) {  // Business rules enforced
            m_balance -= amount;
            return true;  // Success
        }
        return false;  // Invalid operation
    }
    
    void deposit(double amount) {
        if (amount > 0) {  // Only positive deposits allowed
            m_balance += amount;
        }
    }
    
    double getBalance() const { return m_balance; }  // Safe read access
};