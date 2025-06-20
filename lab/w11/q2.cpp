#include <iostream>
#include <string>
using namespace std;

// Base class: HospitalEmployee
class HospitalEmployee {
protected:
    string employeeId;
    string name;
    double salary;
    
public:
    // Constructor
    HospitalEmployee(string id, string empName, double empSalary) 
        : employeeId(id), name(empName), salary(empSalary) {
    }
    
    // Display basic employee info
    void displayInfo() const {
        cout << "Employee ID: " << employeeId << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};

// Derived class: Doctor (inherits from HospitalEmployee)
class Doctor : public HospitalEmployee {
protected:
    string specialty;  // Unique attribute for Doctor
    
public:
    // Constructor
    Doctor(string id, string docName, double docSalary, string docSpecialty) 
        : HospitalEmployee(id, docName, docSalary), specialty(docSpecialty) {
    }
    
    // Override the display method
    void displayInfo() const {
        HospitalEmployee::displayInfo();  // Call base class method
        cout << "Specialty: " << specialty << endl;
    }
};

// Derived class: Surgeon (inherits from Doctor)
class Surgeon : public Doctor {
private:
    bool isOperating;  // Unique attribute for Surgeon
    
public:
    // Constructor
    Surgeon(string id, string surgeonName, double surgeonSalary, 
            string surgeonSpecialty, bool currentlyOperating = false) 
        : Doctor(id, surgeonName, surgeonSalary, surgeonSpecialty), 
          isOperating(currentlyOperating) {
    }
    
    // Override the display method
    void displayInfo() const {
        Doctor::displayInfo();  // Call parent class method
        cout << "Currently Operating: " << (isOperating ? "Yes" : "No") << endl;
    }

    
    void finishSurgery() {
        isOperating = false;
        cout << "Dr. " << name << " has completed the surgery." << endl;
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 15:54:10" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    cout << "\n--- HOSPITAL STAFF DEMONSTRATION ---" << endl;
    
    // Create a base HospitalEmployee
    HospitalEmployee nurse("E10045", "Sarah Johnson", 55000);
    cout << "\n1. HOSPITAL EMPLOYEE:" << endl;
    nurse.displayInfo();
    
    // Create a Doctor (derived from HospitalEmployee)
    Doctor physician("D20089", "Michael Chen", 175000, "Cardiology");
    cout << "\n2. DOCTOR:" << endl;
    physician.displayInfo(); // Inherited from HospitalEmployee
    
    // Create a Surgeon (derived from Doctor)
    Surgeon surgeon("S30567", "Emily Rodriguez", 280000, "Neurosurgery");
    cout << "\n3. SURGEON:" << endl;
    surgeon.displayInfo();
    return 0;
}