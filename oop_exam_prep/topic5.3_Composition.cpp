/*
"part-of"
The strongest relationship - parts cannot exist without the whole.
*/

#include <iostream>
using namespace std;

class Triangle {
private:
    Point m_corner1, m_corner2, m_corner3;  // Triangle IS COMPOSED OF points
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
        : m_corner1{p1}, m_corner2{p2}, m_corner3{p3} {}
    
    double getPerimeter() const {
        // Calculate using the three corner points
        return distance(m_corner1, m_corner2) + 
               distance(m_corner2, m_corner3) + 
               distance(m_corner3, m_corner1);
    }
};
// When the triangle is destroyed, its corner points are automatically destroyed
// The points have no independent existence outside the triangle