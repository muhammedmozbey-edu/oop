#include <iostream>
#include <vector>
using namespace std;

// Stack Abstract Data Type
template<typename T>
class Stack {
private:
    vector<T> data;  // Implementation hidden
    
public:
    // Public interface - what the stack can do
    void push(const T& item) {
        data.push_back(item);
        cout << "Pushed: " << item << endl;
    }
    
    T pop() {
        if (empty()) {
            throw runtime_error("Stack is empty!");
        }
        T item = data.back();
        data.pop_back();
        cout << "Popped: " << item << endl;
        return item;
    }
    
    T top() const {
        if (empty()) {
            throw runtime_error("Stack is empty!");
        }
        return data.back();
    }
    
    bool empty() const {
        return data.empty();
    }
    
    size_t size() const {
        return data.size();
    }
    
    // Implementation details are completely hidden
    // User doesn't know if it's array, vector, linked list, etc.
};

int main() {
    Stack<int> intStack;
    Stack<string> stringStack;
    
    // User only interacts with the abstract interface
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    
    cout << "Top element: " << intStack.top() << endl;
    cout << "Stack size: " << intStack.size() << endl;
    
    while (!intStack.empty()) {
        intStack.pop();
    }
    
    stringStack.push("First");
    stringStack.push("Second");
    stringStack.push("Third");
    
    cout << "\nString stack contents:" << endl;
    while (!stringStack.empty()) {
        stringStack.pop();
    }
    
    return 0;
}