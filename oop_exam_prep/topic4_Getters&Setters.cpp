/*
This builds directly on encapsulation. 
When you make data private, you need controlled ways to access and modify it. 
This is where getters (accessors) and setters (mutators) come in.

Why Not Just Make Everything Public? 
Because setters let you enforce business rules and validate data. 
Notice how setPassword refuses to accept passwords that are too short. 
This level of control is impossible with direct public access.

Const Methods: Notice the const keyword in the getter. T
his is a promise that the method won't modify the object's state. 
Const objects can only call const methods, which is why getters should usually be const while setters cannot be.
*/

#include <iostream>
using namespace std;

class Account {
private:
    string m_mailAddress;
    string m_password;
    
public:
    // Accessor (getter) - read-only access
    string getMailAddress() const { 
        return m_mailAddress; 
    }
    
    // Mutator (setter) - controlled write access
    void setPassword(const string& newPassword) {
        if (newPassword.length() >= 8) {  // Business rule: minimum 8 characters
            m_password = newPassword;
        } else {
            cout << "Password must be at least 8 characters\n";
        }
    }
    
    void setMailAddress(const string& email) {
        // Could add validation here (check for @ symbol, etc.)
        m_mailAddress = email;
    }
};