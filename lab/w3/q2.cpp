#include <iostream>
using namespace std;

class Computer {
private:
    int ram;
    int storage;
    string cpu;
    string gpu;
    string os;
public:
    Computer(int r, int s, string c, string g, string o) : ram(r), storage(s), cpu(c), gpu(g), os(o) {}

    void displaySpecs() {
        cout << "Computer Specifications:" << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
        cout << "CPU: " << cpu << endl;
        cout << "GPU: " << gpu << endl;
        cout << "OS: " << os << endl;
    }
};

int main() {
    Computer myComputer(32, 1, "AMD Ryzen 9", "NVIDIA GeForce RTX 5090", "Ubuntu");
    myComputer.displaySpecs();

    return 0;
}