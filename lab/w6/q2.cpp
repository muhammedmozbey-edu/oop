#include <iostream>
using namespace std;

class Student {
private:
    string name;
    long long id;

    static long long nextId;
    
public:
    Student(string n) : name(n) {
        id = nextId;
        nextId++;
    }

    string getName() const {
        return name;
    }

    long long getId() const {
        return id;
    }

    void displayInfo() const {
        cout << "Student Name: " << name << ", ID: " << id << endl;
    }

    static long long getStudentCount() {
        return nextId - 5001230001; // Assuming the first ID starts at 5001230001
    }
};

long long Student::nextId = 5001230001; // Static member initialization

int main() {
    cout << "Current Date and Time: 2025-06-19 15:03:07" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    // Create some student objects
    cout << "\nRegistering students for Fall 2025 semester:" << endl;
    Student student1("Emma Johnson");
    Student student2("Daniel Smith");
    Student student3("Sophia Garcia");
    Student student4("Michael Wong");
    
    // Display all students' information
    cout << "\nStudent Records:" << endl;
    cout << "---------------------" << endl;
    student1.displayInfo();
    student2.displayInfo();
    student3.displayInfo();
    student4.displayInfo();
    
    // Get total student count
    cout << "\nTotal number of students registered: " << Student::getStudentCount() << endl;
    
    // Create one more student
    cout << "\nLate registration:" << endl;
    Student student5("Olivia Martinez");
    
    cout << "\nUpdated student count: " << Student::getStudentCount() << endl;
    
    return 0;
}