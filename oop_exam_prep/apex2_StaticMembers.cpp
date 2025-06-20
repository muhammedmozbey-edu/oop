/*
Static members belong to the class itself, not to individual objects

When to Use Static:

Counters shared by all objects
Class-wide constants
Utility functions that don't need object state
Factory methods that create objects
*/

#include <iostream>
using namespace std;

class Student {
private:
    string m_name;
    int m_id;
    static int s_nextID;           // Shared by all students
    static int s_studentCount;     // Count of existing students
    
public:
    Student(const string& name) : m_name{name}, m_id{s_nextID++} {
        s_studentCount++;
        cout << "Student " << m_id << " created. Total students: " << s_studentCount << "\n";
    }
    
    ~Student() {
        s_studentCount--;
    }
    
    // Static method - can be called without an object
    static int getStudentCount() {
        return s_studentCount;
    }
    
    static void resetIDCounter() {
        s_nextID = 5001230001;  // As specified in your exercise
    }
    
    int getID() const { return m_id; }
};

/*
// Static members must be defined outside the class
int Student::s_nextID = 5001230001;
int Student::s_studentCount = 0;

// Usage
Student alice{"Alice"};           // ID: 5001230001
Student bob{"Bob"};               // ID: 5001230002
cout << Student::getStudentCount() << endl;  // Called on class, not object
*/