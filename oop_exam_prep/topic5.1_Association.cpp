/*
"uses-a"
Objects can communicate but have independent lifecycles.
*/

#include <iostream>
using namespace std;

class Student {
private:
    vector<Course*> m_courses;  // Student knows about courses
public:
    void enrollIn(Course* course) {
        m_courses.push_back(course);
    }
};

class Course {
private:
    vector<Student*> m_students;  // Course knows about students
public:
    void addStudent(Student* student) {
        m_students.push_back(student);
    }
};
// Students and courses exist independently - when a course is cancelled,
// students aren't destroyed, and when a student graduates, courses remain