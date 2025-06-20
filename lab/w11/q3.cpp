#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int id;
    Person(string n, int i) {
    name = n;
    id = i;
    cout << "Person constructor is called." << endl;
    }
};

class Student : public Person {
public:
    double gpa;
    Student(string n, int i, double g) : Person(n, i) {
    gpa = g;
    cout << "Student constructor is called." << endl;
    }
};

class Assistant : public Person {
public:
    int lectureAssisted;
    Assistant(string n, int i, int l) : Person(n, i) {
    lectureAssisted = l;
    cout << "Assistant constructor is called." << endl;
    }
};

class LearningAssistant : public Student, public Assistant {
public:
    LearningAssistant(string n, int id, double g, int l) : Student(n, id, g),
    Assistant(n, id, l) {
    cout << "LearningAssistant constructor is called." << endl;
    }
};

int main() {
    LearningAssistant elif("Elif Tokay", 12345, 3.9, 5);
    cout << "\n--- Elif's Info ---" << endl;
    cout << "Name: " << elif.Student::name << endl;
    cout << "ID: " << elif.Student::id << endl;
    cout << "GPA: " << elif.gpa << endl;
    cout << "Lectures Assisted: " << elif.lectureAssisted << endl;
    return 0;
}