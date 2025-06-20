/*
Polymorphism is the ability for objects of different types to be treated uniformly through a common interface. 
This is where inheritance really shows its power.

virtual: Enables polymorphism, allows derived classes to override
override: Explicitly states you're overriding a virtual function (catches typos)
final: Prevents further overriding or inheritance

Abstract Classes vs Interfaces: An abstract class (like Shape above) contains at least one pure virtual function and cannot be instantiated. 
It forces derived classes to implement the pure virtual functions, ensuring a common interface.
*/

#include <iostream>
using namespace std;

class Shape {  // Abstract base class
public:
    virtual double getArea() const = 0;  // Pure virtual function
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double m_width, m_height;
public:
    Rectangle(double w, double h) : m_width{w}, m_height{h} {}
    
    double getArea() const override {
        return m_width * m_height;
    }
    
    void draw() const override {
        cout << "Drawing rectangle " << m_width << "x" << m_height << "\n";
    }
};

class Circle : public Shape {
private:
    double m_radius;
public:
    Circle(double r) : m_radius{r} {}
    
    double getArea() const override {
        return 3.14159 * m_radius * m_radius;
    }
    
    void draw() const override {
        cout << "Drawing circle with radius " << m_radius << "\n";
    }
};

// The magic of polymorphism
void processShape(const Shape& shape) {  // Takes ANY shape
    shape.draw();        // Calls the correct draw() for the actual type
    cout << "Area: " << shape.getArea() << "\n";
}

int main() {
    Rectangle rect{5, 3};
    Circle circle{4};
    
    processShape(rect);    // Calls Rectangle's methods
    processShape(circle);  // Calls Circle's methods
    
    Shape* rectPtr = &rect;
    Shape* circPtr = &circle;

    processShape(*rectPtr);    // Calls Rectangle's methods
    processShape(*circPtr);    // Calls Circle's methods   
}