#include <iostream>
#include <string>
using namespace std;

// Base class
class Notification {
public:
    // Non-virtual method
    void send() {
        cout << "Base Notification: Generic notification sent" << endl;
    }
};

// Derived class
class EmailNotification : public Notification {
public:
    // Redefining the send method (not overriding)
    void send() {
        cout << "Email Notification: Sending notification via email" << endl;
    }
};

// Another derived class
class SMSNotification : public Notification {
public:
    // Redefining the send method (not overriding)
    void send() {
        cout << "SMS Notification: Sending notification via text message" << endl;
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 16:26:07" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    cout << "\n--- Q1: What happens without 'virtual'? ---" << endl;
    
    // Create objects of derived classes
    EmailNotification email;
    SMSNotification sms;
    
    // Direct calls work as expected
    cout << "Direct call to email.send():" << endl;
    email.send();
    
    cout << "\nDirect call to sms.send():" << endl;
    sms.send();
    
    // Using base class pointers
    Notification* ptr1 = &email;
    Notification* ptr2 = &sms;
    
    cout << "\nCalling send() through base class pointer to EmailNotification:" << endl;
    ptr1->send();
    
    cout << "\nCalling send() through base class pointer to SMSNotification:" << endl;
    ptr2->send();
    
    return 0;
}