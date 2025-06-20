#include <iostream>
using namespace std;

class Account {
private:
    string mailAddress;
    string password;

public:
    Account(string mA, string p) : mailAddress(mA), password(p) {}

    string getMailAddress() const {
        return mailAddress;
    }
    string getPassword() const {
        return password;
    }
    void setMailAddress(string mA) {
        mailAddress = mA;
    }
    void setPassword(string p) {
        password = p;
    }

    void displayAccountInfo() const {
        cout << "Mail Address: " << mailAddress << endl;
        cout << "Password: " << password << endl;
    }
};

int main() {
    Account myAccount("user@example.com", "securepassword123");
    myAccount.displayAccountInfo();

    cout << "Updating mail address and password..." << endl;
    myAccount.setMailAddress("newuser@example.com");

    myAccount.setPassword("newsecurepassword456");
    myAccount.displayAccountInfo();

    cout << "Updated Account Information:" << endl;
    myAccount.displayAccountInfo();

    cout << "Using getters to access mail address and password:" << endl;
    cout << "Mail Address: " << myAccount.getMailAddress() << endl;
    cout << "Password: " << myAccount.getPassword() << endl;
    return 0;
}