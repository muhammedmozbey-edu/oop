#include <iostream>
using namespace std;

class Person {
protected:
    string m_name;
    int m_id;
public:
    Person(string name, int id) : m_name{name}, m_id{id} {}
};

class Student : public Person {
protected:
    double m_gpa;
public:
    Student(string name, int id, double gpa) 
        : Person{name, id}, m_gpa{gpa} {}
};

class Assistant : public Person {
protected:
    int m_lectureAssisted;
public:
    Assistant(const string& name, int id, int lectures)
        : Person{name, id}, m_lectureAssisted{lectures} {}
};

// Multiple inheritance - inherits from both Student AND Assistant
class LearningAssistant : public Student, public Assistant {
public:
    LearningAssistant(const string& name, int id, double gpa, int lectures)
        : Student{name, id, gpa}, Assistant{name, id, lectures} {}
    
    void displayInfo() const {
        cout << "Name: " << Student::m_name << "\n";  // Must specify which m_name
        cout << "GPA: " << m_gpa << "\n";
        cout << "Lectures Assisted: " << m_lectureAssisted << "\n";
    }
};