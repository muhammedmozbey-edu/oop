/*
Inheritance lets you create specialized versions of existing classes. 
This is fundamentally different from composition - instead of "having" components, inheritance expresses that one thing "is a kind of" another thing.

public inheritance: "is-a" relationship preserved, derived objects can be used wherever base objects are expected
private inheritance: "implemented-in-terms-of" relationship, used for implementation reuse without exposing the interface
protected inheritance: Rarely used, creates a hybrid relationship
*/

#include <iostream>
using namespace std;

// Base class - general concept
class Media {
protected:  // Protected allows derived classes to access
    int m_quality;
    double m_size;
    
public:
    Media(int quality, double size) : m_quality{quality}, m_size{size} {}
    
    virtual void display() const {  // Virtual allows overriding
        cout << "Quality: " << m_quality << ", Size: " << m_size << "\n";
    }
    
};

// Derived class - specialized version
class Photo : public Media {
private:
    bool m_isFilterOn;
    
public:
    Photo(int quality, double size, bool filter) 
        : Media{quality, size}, m_isFilterOn{filter} {}  // Call base constructor
    
    void display() const override {  // Override base implementation
        Media::display();  // Call base version first
        cout << "Filter: " << (m_isFilterOn ? "On" : "Off") << "\n";
    }
    
    void toggleFilter() { m_isFilterOn = !m_isFilterOn; }
};

class Video : public Media {
private:
    double m_duration;
    
public:
    Video(int quality, double size, double duration)
        : Media{quality, size}, m_duration{duration} {}
    
    void display() const override {
        Media::display();
        cout << "Duration: " << m_duration << " seconds\n";
    }
    
    void play() { cout << "Playing video...\n"; }
};