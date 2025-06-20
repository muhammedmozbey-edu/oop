#include <iostream>
#include <string>
using namespace std;

// First parent class
class MedSchool {
protected:
    string dean;
    
public:
    MedSchool(string deanName) : dean(deanName) {
    }
    
    void displayMedSchoolInfo() const {
        cout << "Medical School Dean: " << dean << endl;
    }
};

// Second parent class
class Hospital {
protected:
    string chiefDoctor;
    
public:
    Hospital(string doctorName) : chiefDoctor(doctorName) {
    }
    
    void displayHospitalInfo() const {
        cout << "Hospital Chief Doctor: " << chiefDoctor << endl;
    }
};

// Child class with multiple inheritance
class UniversityHospital : public MedSchool, public Hospital {
private:
    string name;
    int foundingYear;
    
public:
    UniversityHospital(string hospitalName, int year, string deanName, string doctorName)
        : MedSchool(deanName), Hospital(doctorName), name(hospitalName), foundingYear(year) {
    }
    
    void displayAllInfo() const {
        cout << "\n--- UNIVERSITY HOSPITAL INFO ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Founded: " << foundingYear << endl;
        displayMedSchoolInfo();
        displayHospitalInfo();
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 16:15:23" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    // Create a university hospital
    UniversityHospital hospital1(
        "Memorial University Medical Center", 
        1965, 
        "Dr. Sarah Johnson", 
        "Dr. Robert Chen"
    );
    
    // Display info
    hospital1.displayAllInfo();
    
    // We can also access methods from parent classes directly
    cout << "\nAccessing parent class methods:" << endl;
    hospital1.displayMedSchoolInfo();
    hospital1.displayHospitalInfo();
    
    return 0;
}