#include <iostream>
using namespace std;

class Patient {
private:
    void displayMedication() {
        cout << "Patient Medication Information:" << endl;
        cout << "Current Medication: " << endl;
        cout << "Last Updated: 2025-06-19" << endl;
    }

    const string DOCTOR_PASSWORD = "doctor123";

    string name;
    string surname;
    string medication;

public:
    Patient(string n, string s, string m) : name(n), surname(s), medication(m) {}

    void displayInfo() {
        cout << "Patient Name: " << name << " " << surname << endl;
        cout << "Medication: " << medication << endl;
    }

    void accessMedicationInfo(const string& password) {
        if (password == DOCTOR_PASSWORD) {
            displayMedication();
        } else {
            cout << "Access Denied: Incorrect Password" << endl;
        }
    }
};

int main() {
    Patient patient("John", "Doe", "Aspirin 100mg");
    patient.displayInfo();

    cout << "Attempting access with incorrect password:" << endl;
    patient.accessMedicationInfo("wrongpassword");

    cout << "Attempting access with correct password:" << endl;
    patient.accessMedicationInfo("doctor123"); 

    return 0;
}