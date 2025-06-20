#include <iostream>
using namespace std;

// Function template
template<typename T>
T maximum(T a, T b) {
    cout << "Generic maximum called" << endl;
    return (a > b) ? a : b;
}

// Template specialization
template<>
const char* maximum<const char*>(const char* a, const char* b) {
    cout << "String maximum specialization called" << endl;
    return (strcmp(a, b) > 0) ? a : b;
}

// Class template
template<typename T>
class Container {
private:
    T data;
    
public:
    Container(T value) : data(value) {}
    
    void display() {
        cout << "Container holds: " << data << endl;
    }
    
    T getValue() { return data; }
};

int main() {
    // Template function polymorphism
    cout << "Max of 10, 20: " << maximum(10, 20) << endl;
    cout << "Max of 3.14, 2.71: " << maximum(3.14, 2.71) << endl;
    cout << "Max of strings: " << maximum("apple", "banana") << endl;
    
    // Template class polymorphism
    Container<int> intContainer(42);
    Container<string> stringContainer("Hello");
    
    intContainer.display();
    stringContainer.display();
    
    return 0;
}