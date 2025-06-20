#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Actor class - exists independently
class Actor {
private:
    string name;
    
public:
    Actor(string actorName) : name(actorName) {
        cout << "Actor created: " << name << endl;
    }
    
    ~Actor() {
        cout << "Actor deleted: " << name << endl;
    }
    
    string getName() const { return name; }
};

// Episode class - part of a Series (composition)
class Episode {
private:
    string title;
    int number;
    
public:
    Episode(string episodeTitle, int episodeNumber) 
        : title(episodeTitle), number(episodeNumber) {
        cout << "Episode created: " << title << endl;
    }
    
    ~Episode() {
        cout << "Episode deleted: " << title << endl;
    }
    
    string getTitle() const { return title; }
};

// Series class - has Episodes (composition) and Actors (aggregation)
class Series {
private:
    string title;
    vector<Episode> episodes;  // Composition: owns episodes
    vector<Actor*> actors;      // Aggregation: references actors
    
public:
    Series(string seriesTitle) : title(seriesTitle) {
        cout << "Series created: " << title << endl;
    }
    
    void addEpisode(string episodeTitle, int episodeNumber) {
        episodes.push_back(Episode(episodeTitle, episodeNumber));
    }
    
    void addActor(Actor* actor) {
        actors.push_back(actor);
        cout << "Added " << actor->getName() << " to " << title << endl;
    }
    
    void showInfo() const {
        cout << "\n--- " << title << " ---" << endl;
        cout << "Episodes: " << episodes.size() << endl;
        for (Episode ep : episodes) {
            cout << "- " << ep.getTitle() << endl;
        }
        
        cout << "Cast: " << endl;
        for (Actor* actor : actors) {
            cout << "- " << actor->getName() << endl;
        }
    }
};

int main() {
    cout << "Current Date and Time: 2025-06-19 15:48:25" << endl;
    cout << "Current User: muhammedmozbey-edu" << endl;
    
    // Create actors (independent objects)
    Actor* actor1 = new Actor("Jennifer Lawrence");
    Actor* actor2 = new Actor("Pedro Pascal");
    
    cout << "\n--- CREATING FIRST SERIES ---" << endl;
    {
        // Create a series with episodes and actors
        Series* breakingCode = new Series("Breaking Code");
        
        // Add episodes (composition)
        breakingCode->addEpisode("Pilot", 1);
        breakingCode->addEpisode("The Bug", 2);
        
        // Add actors (aggregation)
        breakingCode->addActor(actor1);
        breakingCode->addActor(actor2);
        
        breakingCode->showInfo();
        
        cout << "\n--- DELETING SERIES ---" << endl;
        delete breakingCode;  // This deletes all episodes but not actors
    }
    
    cout << "\n--- ACTORS STILL EXIST ---" << endl;
    // Proof that actors still exist after series deletion
    cout << "Actor still in memory: " << actor1->getName() << endl;
    cout << "Actor still in memory: " << actor2->getName() << endl;
    
    cout << "\n--- CREATING SECOND SERIES ---" << endl;
    // Create another series with the same actors
    Series* techDrama = new Series("Tech Drama");
    techDrama->addEpisode("New Start", 1);
    techDrama->addActor(actor2);  // Reuse actor2 in another series
    
    techDrama->showInfo();
    
    // Clean up
    cout << "\n--- FINAL CLEANUP ---" << endl;
    delete techDrama;
    delete actor1;
    delete actor2;
    
    return 0;
}