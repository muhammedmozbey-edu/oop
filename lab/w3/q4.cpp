#include <iostream>
using namespace std;

class Order {
private:
    int prodCode;
    int quantity;
    double pricePerItem;
public:
    Order(int code, int qty, double price) : prodCode(code), quantity(qty), pricePerItem(price) {}

    double calculateTotal() const {
        return quantity * pricePerItem;
    }

    void displayOrder() const {
        cout << "Product Code: " << prodCode << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price per Item: $" << pricePerItem << endl;
        cout << "Total Price: $" << calculateTotal() << endl;
    }
};

int main() {
    Order myOrder(101, 5, 19.99);
    myOrder.displayOrder();
    cout << "Total Price: $" << myOrder.calculateTotal() << endl;
    return 0;
}