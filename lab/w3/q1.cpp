#include <iostream>
using namespace std;

class Movie {
private:
    string title;
    int year;
public:
    Movie(string t, int y) : title(t), year(y) {}

    string getTitle() const {
        return title;
    }
    int getYear() const {
        return year;
    }

    void display() const {
        cout << "Movie: " << title << " (" << year << ")" << endl;
    }
};

int main() {
    Movie movie("Inception", 2010);
    movie.display();

    cout << "Title: " << movie.getTitle() << endl;
    cout << "Year: " << movie.getYear() << endl;

    return 0;
}