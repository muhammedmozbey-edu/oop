#include <iostream>
using namespace std;

class Song {
private:
    string title;
    string artist;
    int duration; // in seconds
    bool isOnSpotify;
public:
    Song(string t, string a, int d, bool s) : title(t), artist(a), duration(d), isOnSpotify(s) {}

    void displayInfo() {
        cout << "Song Title: " << title << endl;
        cout << "Artist: " << artist << endl;
        cout << "Duration: " << duration << " seconds" << endl;
        cout << "Available on Spotify: " << (isOnSpotify ? "Yes" : "No") << endl;
    }
};

int main() {
    Song mySong("Shape of You", "Ed Sheeran", 263, true);
    mySong.displayInfo();

    return 0;
}