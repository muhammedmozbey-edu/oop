/*
"has-a"
A stronger relationship where one object owns others, 
but the parts can exist independently.
*/

#include <iostream>
#include <vector>
using namespace std;

class Department {
private:
    vector<Professor*> m_professors;  // Department has professors
public:
    void addProfessor(Professor* prof) {
        m_professors.push_back(prof);
    }
};
// If the department closes, professors can move to other departments