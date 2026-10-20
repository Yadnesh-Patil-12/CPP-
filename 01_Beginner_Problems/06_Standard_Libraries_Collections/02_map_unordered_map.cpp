#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    map<int, string> mp;

    mp[1] = "Apple";
    mp[2] = "Banana";
    mp[3] = "Mango";

    cout << "Ordered Map:" << endl;

    for (auto p : mp) {
        cout << p.first << " : " << p.second << endl;
    }

    unordered_map<string, int> marks;

    marks["Amit"] = 85;
    marks["Rahul"] = 90;
    marks["Neha"] = 95;

    cout << "\nUnordered Map:" << endl;

    for (auto p : marks) {
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}