#include <iostream>
#include <vector>
using namespace std;

class ClubMember {
private:
    string name;
    string position;
public:
    ClubMember(string n, string p) : name(n), position(p) {}

    void displayInfo() const {
        cout << "Member Name: " << name << endl;
        cout << "Position: " << position << endl;
    }

    string getName() const {
        return name;
    }
    string getPosition() const {
        return position;
    }
};

int main() {
    vector<ClubMember> members;
    members.push_back(ClubMember("Alice", "President"));
    members.push_back(ClubMember("Bob", "Vice President"));
    members.push_back(ClubMember("Charlie", "Secretary"));

    cout << "Club Members Information:" << endl;
    for (int i = 0; i < members.size(); ++i) {
        cout << "Member " << (i + 1) << ":" << endl;
        members[i].displayInfo();
    }

    cout << "Total number of members: " << members.size() << endl;

    return 0;
}