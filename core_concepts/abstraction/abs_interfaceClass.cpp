#include <iostream>
using namespace std;

// Pure interface - only pure virtual functions
class Drawable {
public:
    virtual void draw() = 0;
    virtual void hide() = 0;
    virtual ~Drawable() = default;
};

class Printable {
public:
    virtual void print() = 0;
    virtual ~Printable() = default;
};

// Class implementing multiple interfaces
class Document : public Drawable, public Printable {
private:
    string content;
    bool visible = false;
    
public:
    Document(string text) : content(text) {}
    
    // Implement Drawable interface
    void draw() override {
        visible = true;
        cout << "Drawing document: " << content << endl;
    }
    
    void hide() override {
        visible = false;
        cout << "Hiding document" << endl;
    }
    
    // Implement Printable interface
    void print() override {
        cout << "Printing: " << content << endl;
    }
    
    bool isVisible() const { return visible; }
};

class Image : public Drawable {
private:
    string filename;
    bool visible = false;
    
public:
    Image(string file) : filename(file) {}
    
    void draw() override {
        visible = true;
        cout << "Displaying image: " << filename << endl;
    }
    
    void hide() override {
        visible = false;
        cout << "Hiding image: " << filename << endl;
    }
};

// Functions that work with interfaces
void makeVisible(Drawable& item) {
    item.draw();
}

void makeHardCopy(Printable& item) {
    item.print();
}

int main() {
    Document doc("Hello World");
    Image img("photo.jpg");
    
    // Using interface polymorphism
    makeVisible(doc);
    makeVisible(img);
    
    makeHardCopy(doc);
    // makeHardCopy(img);  // ERROR! Image doesn't implement Printable
    
    // Interface pointer arrays
    Drawable* items[] = {&doc, &img};
    
    cout << "\nHiding all drawable items:" << endl;
    for (Drawable* item : items) {
        item->hide();
    }
    
    return 0;
}