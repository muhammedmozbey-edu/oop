#include <iostream>
using namespace std;

class Parent {
protected:
    int protectedData = 20;
    
private:
    int privateData = 30;
    
public:
    int publicData = 10;
    
    void showData() {
        cout << "Public: " << publicData << endl;
        cout << "Protected: " << protectedData << endl;
        cout << "Private: " << privateData << endl;
    }
};

class Child : public Parent {
public:
    void accessParentData() {
        cout << "Child accessing public: " << publicData << endl;      // OK
        cout << "Child accessing protected: " << protectedData << endl; // OK
        // cout << "Child accessing private: " << privateData << endl;  // ERROR!
    }
};

int main() {
    Parent p;
    cout << "External access to public: " << p.publicData << endl;     // OK
    // cout << "External access to protected: " << p.protectedData;    // ERROR!
    // cout << "External access to private: " << p.privateData;        // ERROR!
    
    Child c;
    c.accessParentData();
    
    return 0;
}