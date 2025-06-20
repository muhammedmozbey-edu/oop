#include <iostream>
#include <vector>
using namespace std;

class Engine {
public:
    void start() { cout << "Engine started." << endl; }
    void stop() { cout << "Engine stopped." << endl; }
    bool isRunning() { return running; }
    
private:
    bool running = false;
};

class Car : private Engine {  // Car is implemented-in-terms-of Engine
private:
    string model;
    
public:
    Car(string m) : model(m) {}
    
    void startCar() {
        cout << "Starting " << model << endl;
        start();  // Can access Engine's public methods internally
    }
    
    void stopCar() {
        cout << "Stopping " << model << endl;
        stop();   // Can access Engine's public methods internally
    }
};

int main() {
    Car car("Toyota");
    
    car.startCar();
    car.stopCar();
    
    // Engine* ptr = &car;     // ERROR! No IS-A relationship
    // car.start();            // ERROR! Engine interface not public
    
    return 0;
}