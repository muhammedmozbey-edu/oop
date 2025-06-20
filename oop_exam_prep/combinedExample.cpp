#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

// Abstract base class demonstrating polymorphism
class GameEntity {
protected:
    string m_name;
    int m_health;
    static int s_entityCount;
    
public:
    GameEntity(const string& name, int health) : m_name{name}, m_health{health} {
        s_entityCount++;
    }
    
    virtual ~GameEntity() { s_entityCount--; }
    
    // Pure virtual function - makes this an abstract class
    virtual void performAction() const = 0;
    virtual void takeDamage(int damage) = 0;
    
    // Template method pattern
    void update() {
        performAction();
        if (m_health <= 0) {
            cout << m_name << " has been defeated!\n";
        }
    }
    
    static int getEntityCount() { return s_entityCount; }
    string getName() const { return m_name; }
    int getHealth() const { return m_health; }
};

int GameEntity::s_entityCount = 0;

// Inheritance and polymorphism
class Player : public GameEntity {
private:
    vector<string> m_inventory;  // Composition
    
public:
    Player(const string& name) : GameEntity{name, 100} {}
    
    void performAction() const override {
        cout << m_name << " explores the dungeon...\n";
    }
    
    void takeDamage(int damage) override {
        m_health -= damage;
        cout << m_name << " takes " << damage << " damage! Health: " << m_health << "\n";
    }
    
    void addItem(const string& item) {
        m_inventory.push_back(item);
        cout << m_name << " picked up: " << item << "\n";
    }
};

class Enemy : public GameEntity {
private:
    int m_attackPower;
    
public:
    Enemy(const string& name, int health, int attack) 
        : GameEntity{name, health}, m_attackPower{attack} {}
    
    void performAction() const override {
        cout << m_name << " searches for targets...\n";
    }
    
    void takeDamage(int damage) override {
        m_health -= damage;
        cout << m_name << " takes " << damage << " damage! Health: " << m_health << "\n";
    }
    
    int getAttackPower() const { return m_attackPower; }
};

// Template class for generic game systems
template<typename T>
class GameManager {
private:
    vector<unique_ptr<T>> m_entities;
    
public:
    void addEntity(unique_ptr<T> entity) {
        m_entities.push_back(move(entity));
    }
    
    void updateAll() {
        for (auto& entity : m_entities) {
            entity->update();
        }
    }
    
    size_t getCount() const { return m_entities.size(); }
};

// Demonstration of all concepts working together
int main() {
    cout << "=== Object-Oriented Programming Demo ===\n\n";
    
    // Polymorphism with smart pointers
    vector<unique_ptr<GameEntity>> entities;
    
    entities.push_back(make_unique<Player>("Hero"));
    entities.push_back(make_unique<Enemy>("Goblin", 50, 15));
    entities.push_back(make_unique<Enemy>("Orc", 80, 25));
    
    cout << "Total entities: " << GameEntity::getEntityCount() << "\n\n";
    
    // Polymorphic behavior
    for (auto& entity : entities) {
        entity->performAction();  // Calls correct version for each type
        entity->takeDamage(10);   // Polymorphic damage handling
    }
    
    cout << "\n=== Template System Demo ===\n";
    
    // Template usage
    GameManager<Player> playerManager;
    playerManager.addEntity(make_unique<Player>("Warrior"));
    playerManager.addEntity(make_unique<Player>("Mage"));
    
    cout << "Players managed: " << playerManager.getCount() << "\n";
    playerManager.updateAll();
    
    return 0;
}