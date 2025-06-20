#include <iostream>
using namespace std;

class Animal {
protected:
    string name;
    
public:
    Animal(string n) : name(n) {}
    
    void eat() { cout << name << " is eating." << endl; }
    void sleep() { cout << name << " is sleeping." << endl; }
    
    virtual void makeSound() { cout << name << " makes a sound." << endl; }
    virtual ~Animal() = default;
};

class Dog : public Animal {  // Dog IS-A Animal
public:
    Dog(string n) : Animal(n) {}
    
    void makeSound() override { cout << name << " barks: Woof!" << endl; }
    void wagTail() { cout << name << " wags tail." << endl; }
};

class Cat : public Animal {  // Cat IS-A Animal
public:
    Cat(string n) : Animal(n) {}
    
    void makeSound() override { cout << name << " meows: Meow!" << endl; }
    void purr() { cout << name << " purrs." << endl; }
};

int main() {
    Dog dog("Buddy");
    Cat cat("Whiskers");
    
    Animal* animal = &dog;  // Upcasting
    animal->eat();          // Calls Animal's eat
    animal->makeSound();   // Calls Dog's makeSound (polymorphism)

    Animal* anotherAnimal = &cat;  // Upcasting
    anotherAnimal->eat();          // Calls Animal's eat
    anotherAnimal->makeSound();   // Calls Cat's makeSound (polymorphism)   
    
    return 0;
}