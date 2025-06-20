#include <iostream>
#include <string>
using namespace std;

// Base class - Media
class Media {
protected:
    string quality;  // e.g., "HD", "4K", "Low"
    double size;     // in MB

public:
    // Constructor
    Media(string mediaQuality, double mediaSize) 
        : quality(mediaQuality), size(mediaSize) {
    }
    
    // Methods
    double getSize() const {
        return size;
    }
    
    string getQuality() const {
        return quality;
    }
    
    // Display media information
    void displayInfo() const {
        cout << "Quality: " << quality << endl;
        cout << "Size: " << size << " MB" << endl;
    }
};

// Derived class - Photo
class Photo : public Media {
private:
    bool isFilterOn;
    string resolution;  // e.g., "1920x1080"
    
public:
    // Constructor
    Photo(string quality, double size, bool filter, string photoResolution) 
        : Media(quality, size), isFilterOn(filter), resolution(photoResolution) {
    }
    
    // Methods
    bool hasFilter() const {
        return isFilterOn;
    }
    
    // Override displayInfo method
    void displayInfo() const {
        cout << "--- Photo Information ---" << endl;
        Media::displayInfo();  // Call base class method
        cout << "Resolution: " << resolution << endl;
        cout << "Filter: " << (isFilterOn ? "ON" : "OFF") << endl;
    }
};

// Derived class - Video
class Video : public Media {
private:
    int duration;  // in seconds
    string format; // e.g., "MP4", "MOV"
    
public:
    // Constructor
    Video(string quality, double size, int videoDuration, string videoFormat) 
        : Media(quality, size), duration(videoDuration), format(videoFormat) {
    }
    
    // Methods
    int getDuration() const {
        return duration;
    }
    // Override displayInfo method
    void displayInfo() const {
        cout << "--- Video Information ---" << endl;
        Media::displayInfo();  // Call base class method
        cout << "Duration: " << duration << endl;
        cout << "Format: " << format << endl;
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 15:51:44" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    // Create a Photo object
    Photo vacation("High", 5.2, true, "3840x2160");
    
    // Create a Video object
    Video birthday("4K", 256.7, 185, "MP4");
    
    // Display information
    cout << "\n";
    vacation.displayInfo();
    
    cout << "\n";
    birthday.displayInfo();
    

    
    return 0;
}