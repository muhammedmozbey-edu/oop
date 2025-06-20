#include <iostream>
#include <string>
using namespace std;

// 1. Template function to log a value with a label
template<typename T>
void logValue(const string& label, const T& value) {
    cout << "[LOG] " << label << ": " << value << endl;
}

// 3. Template class Logger
template<typename T>
class Logger {
private:
    T value;
    string name;
    
public:
    // Constructor
    Logger(const string& loggerName, const T& initialValue)
        : name(loggerName), value(initialValue) {
    }
    
    // Print method
    void print() const {
        cout << "[" << name << "] Current value: " << value << endl;
    }
    
    // 4. Add method that adds value to itself and prints result
    void add() {
        T result = value + value;
        cout << "[" << name << "] " << value << " + " << value << " = " << result << endl;
        // Note: For demonstration, we're not updating the stored value
    }
    
    // Get and set methods
    T getValue() const {
        return value;
    }
    
    void setValue(const T& newValue) {
        value = newValue;
        cout << "[" << name << "] Value updated to: " << value << endl;
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 16:33:33" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    cout << "\n--- Template Function Demo ---" << endl;
    // 2. Test the template function with different types
    logValue("Integer", 42);
    logValue("Double", 3.14159);
    logValue("String", "Hello, templates!");
    
    cout << "\n--- Template Class Demo ---" << endl;
    // 5. Use Template class with different types
    Logger<float> temperatureSensor("Temperature", 23.5f);
    Logger<int> errorCode("Error", 404);
    Logger<string> statusMessage("Status", "System operational");
    
    // Print current values
    cout << "\nCurrent readings:" << endl;
    temperatureSensor.print();
    errorCode.print();
    statusMessage.print();
    
    // Demonstrate add() functionality
    cout << "\nPerforming add operations:" << endl;
    temperatureSensor.add();  // Adds the temperature to itself
    errorCode.add();          // Adds the error code to itself
    statusMessage.add();      // Concatenates the string with itself
    
    // Update values and print again
    cout << "\nUpdating values:" << endl;
    temperatureSensor.setValue(25.8f);
    errorCode.setValue(200);
    statusMessage.setValue("All systems normal");
    
    cout << "\nFinal readings:" << endl;
    temperatureSensor.print();
    errorCode.print();
    statusMessage.print();
    
    return 0;
}