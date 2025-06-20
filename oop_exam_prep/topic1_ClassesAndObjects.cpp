/*
A class is like a blueprint or template. 
An object is a specific instance created from that blueprint. 
Think of it like this: "Car" is a class (the general concept), while "my red Honda Civic with license plate ABC123" is an object (a specific instance).
*/

#include <iostream>
using namespace std;

// Class definition - the blueprint
class Movie {
private:
    string m_title;        // Attributes define what the object "has"
    int m_releaseYear;
    bool m_isPartOfSeries;
    string m_starring;
    
public:
    // Constructor - how we create objects
    Movie(const string& title, int year, bool series, const string& star)
        : m_title{title}, m_releaseYear{year}, m_isPartOfSeries{series}, m_starring(star) {}
    
    // Methods define what the object "can do"
    void displayInfo() const {
        cout << m_title << " (" << m_releaseYear << ")\n";
        cout << "Starring: " << m_starring << "\n";
        cout << "Part of series: " << (m_isPartOfSeries ? "Yes" : "No") << "\n";
    }
};

// Object creation - using the blueprint
int main() {
    Movie myFavoriteMovie{"The Matrix", 1999, true, "Keanu Reeves"};  // Object creation
    myFavoriteMovie.displayInfo();  // Using object's behavior
    return 0;
}
