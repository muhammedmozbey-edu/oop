/*
Member Initializer Lists
Essential for const members and efficient initialization:

class Student {
private:
    const int m_studentID;  // Constant - must be initialized in constructor
    string m_name;
    static int s_nextID;
    
public:
    Student(const string& name) 
        : m_studentID{s_nextID++}, m_name{name} {  // Initializer list
        // Constructor body - initialization already done
    }
    
    // Copy constructor
    Student(const Student& other) 
        : m_studentID{s_nextID++}, m_name{other.m_name} {
        // Creates new student with new ID but same name
    }
};

int Student::s_nextID = 5001230001;  // Starting ID as specified in your exercise
*/



/*
Copy Constructor Deep Dive
The copy constructor is crucial when your class manages resources:

class Enemy {
private:
    std::string m_type;
    int m_speed;
    int m_damage;
    int m_x, m_y;  // Position
    
public:
    Enemy(const std::string& type, int speed, int damage, int x, int y)
        : m_type{type}, m_speed{speed}, m_damage{damage}, m_x{x}, m_y{y} {}
    
    // Copy constructor - as required in your exercise
    Enemy(const Enemy& other) 
        : m_type{other.m_type}, m_speed{other.m_speed}, m_damage{other.m_damage} {
        // Random position as specified
        m_x = rand() % 800;  // Random x position
        m_y = rand() % 600;  // Random y position
        std::cout << "Enemy respawned at (" << m_x << ", " << m_y << ")\n";
    }
    
    ~Enemy() {
        std::cout << "Enemy destroyed!\n";
        // In destructor, create another enemy (as per your requirement)
        if (// some condition to prevent infinite creation) {
            Enemy* newEnemy = new Enemy(*this);  // Uses copy constructor
            // Note: This creates a memory management challenge in real code
        }
    }
};
*/