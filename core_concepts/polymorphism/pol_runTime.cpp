#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape {
public:
    virtual double area() = 0;        // Pure virtual function
    virtual void display() = 0;      // Pure virtual function
    virtual ~Shape() = default;      // Virtual destructor
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() override {
        return width * height;
    }
    
    void display() override {
        cout << "Rectangle: " << width << "x" << height;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double area() override {
        return 3.14159 * radius * radius;
    }
    
    void display() override {
        cout << "Circle: radius " << radius;
    }
};

// Function that works with any Shape
void printShapeInfo(Shape& shape) {
    shape.display();  // Runtime polymorphism
    cout << ", Area: " << shape.area() << endl;
}

int main() {
    Rectangle rect(5, 10);
    Circle circle(7);
    
    // Runtime polymorphism through references
    printShapeInfo(rect);
    printShapeInfo(circle);
    
    // Runtime polymorphism through pointers
    Shape* shapeRec = &rect;
    Shape* shapeCirc = &circle;

    printShapeInfo(*shapeRec);  // Calls Rectangle's methods
    printShapeInfo(*shapeCirc);  // Calls Circle's methods
    
    return 0;
}