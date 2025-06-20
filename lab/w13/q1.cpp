#include <iostream>
#include <string>
using namespace std;

// Base class
class Card {
private:
    string cardNumber;
    string securityCode;
    string owner;

public:
    // Constructor
    Card(string number, string code, string ownerName) 
        : cardNumber(number), securityCode(code), owner(ownerName) {
    }
    
    // Getter methods
    string getCardNumber() const {
        return cardNumber;
    }
    
    string getSecurityCode() const {
        return securityCode;
    }
    
    string getOwner() const {
        return owner;
    }
};

// Derived class
class CreditCard : public Card {
private:
    int limit;
    
public:
    // Constructor - calls base class constructor and initializes limit
    CreditCard(string number, string code, string ownerName, int creditLimit)
        : Card(number, code, ownerName), limit(creditLimit) {
    }
    
    // Getter method for the additional data member
    int getLimit() const {
        return limit;
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 16:16:48" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    // 1. Create a CreditCard object
    CreditCard myCard("1234-5678-9012-3456", "123", "John Doe", 5000);
    
    // 2. Define a pointer of type Card* and make it point to the CreditCard object
    Card* cardPtr = &myCard;
    
    // 3. Use the pointer to print card information
    cout << "\n--- Card Information (via base class pointer) ---" << endl;
    cout << "Card Number: " << cardPtr->getCardNumber() << endl;
    cout << "Security Code: " << cardPtr->getSecurityCode() << endl;
    cout << "Owner: " << cardPtr->getOwner() << endl;
    
    // Direct access to CreditCard object works fine
    cout << "\n--- Card Information (via direct object) ---" << endl;
    cout << "Card Number: " << myCard.getCardNumber() << endl;
    cout << "Security Code: " << myCard.getSecurityCode() << endl;
    cout << "Owner: " << myCard.getOwner() << endl;
    cout << "Credit Limit: $" << myCard.getLimit() << endl;
    
    // 4. WHY WE CANNOT ACCESS LIMIT THROUGH BASE CLASS POINTER:
    /*
    The following line would cause a compilation error:
    cout << "Credit Limit: $" << cardPtr->getLimit() << endl;
    
    EXPLANATION:
    - The type of 'cardPtr' is Card*, which means the compiler only knows about
      methods and properties defined in the Card class.
    - Even though 'cardPtr' points to a CreditCard object at runtime, the compiler
      only allows access to members that are part of the Card class interface.
    - The 'getLimit()' method is defined in CreditCard class, not in Card class,
      so it's not accessible through a Card pointer.
    - To access 'getLimit()', we would need to cast the pointer to CreditCard*:
      CreditCard* creditCardPtr = static_cast<CreditCard*>(cardPtr);
      cout << "Credit Limit: $" << creditCardPtr->getLimit() << endl;
    */
    
    // Demonstrating the cast solution:
    cout << "\n--- Accessing CreditCard-specific method after casting ---" << endl;
    CreditCard* creditCardPtr = static_cast<CreditCard*>(cardPtr);
    cout << "Credit Limit: $" << creditCardPtr->getLimit() << endl;
    
    return 0;
}