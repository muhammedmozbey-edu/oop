#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
private:
    string name;
    int age;
    
public:
    // Constructor
    Person(string personName, int personAge) 
        : name(personName), age(personAge) {
    }
    
    // Getter methods
    string getName() const {
        return name;
    }
    
    int getAge() const {
        return age;
    }
};

// Derived class using private inheritance
class Customer : private Person {
private:
    string order;
    
public:
    // Constructor
    Customer(string customerName, int customerAge, string customerOrder)
        : Person(customerName, customerAge), order(customerOrder) {
    }
    
    // Wrapper methods to access base class attributes
    string getCustomerName() const {
        return getName();  // Calls Person::getName()
    }
    
    int getCustomerAge() const {
        return getAge();   // Calls Person::getAge()
    }
    
    // Getter for order
    string getOrder() const {
        return order;
    }
    
    // Display customer information
    void displayInfo() const {
        cout << "Customer Name: " << getCustomerName() << endl;
        cout << "Customer Age: " << getCustomerAge() << endl;
        cout << "Current Order: " << order << endl;
    }
};

// Another derived class using private inheritance
class Employee : private Person {
private:
    double salary;
    
public:
    // Constructor
    Employee(string employeeName, int employeeAge, double employeeSalary)
        : Person(employeeName, employeeAge), salary(employeeSalary) {
    }
    
    // Wrapper methods to access base class attributes
    string getEmployeeName() const {
        return getName();  // Calls Person::getName()
    }
    
    int getEmployeeAge() const {
        return getAge();   // Calls Person::getAge()
    }
    
    // Getter for salary
    double getSalary() const {
        return salary;
    }
    
    // Display employee information
    void displayInfo() const {
        cout << "Employee Name: " << getEmployeeName() << endl;
        cout << "Employee Age: " << getEmployeeAge() << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 16:19:31" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    // Create a Customer object
    Customer customer1("John Smith", 35, "Gaming Laptop");
    
    // Create an Employee object
    Employee employee1("Jane Wilson", 28, 65000.00);
    
    // Display information
    cout << "\n--- Customer Information ---" << endl;
    customer1.displayInfo();
    
    cout << "\n--- Employee Information ---" << endl;
    employee1.displayInfo();
    
    /* 
    // The following lines would cause compilation errors because of private inheritance:
    
    cout << customer1.getName();  // Error: getName() is not accessible
    cout << customer1.getAge();   // Error: getAge() is not accessible
    cout << employee1.getName();  // Error: getName() is not accessible
    cout << employee1.getAge();   // Error: getAge() is not accessible
    
    // We must use the wrapper methods instead:
    cout << customer1.getCustomerName();  // Works
    cout << employee1.getEmployeeName();  // Works
    */
    
    return 0;
}