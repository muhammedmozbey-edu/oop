#include <iostream>
using namespace std;

class Ticket {
private:
    string date;
    string name;
    double price;
    double discount;

public:
    Ticket(string d, string n, double p, double disc = 0.0) 
        : date(d), name(n), price(p), discount(disc) {}

        double getFinalPrice() const {
            return price - (price * discount / 100);
        }

    void displayTicketInfo() const {
        cout << "Ticket Date: " << date << endl;
        cout << "Ticket Name: " << name << endl;
        cout << "Ticket Price: $" << price << endl;
        cout << "Discount: " << discount << "%" << endl;
        cout << "Final Price: $" << getFinalPrice() << endl;
    }
};

int main() {
    Ticket ticket1("2025-06-19", "Concert", 100.0, 10.0);
    ticket1.displayTicketInfo();
    cout << endl;

    Ticket ticket2("2025-06-20", "Movie", 15.0);
    ticket2.displayTicketInfo();

    return 0;
}