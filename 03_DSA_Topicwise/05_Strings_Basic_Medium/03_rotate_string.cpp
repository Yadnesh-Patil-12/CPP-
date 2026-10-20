#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, goal;

    cin >> s >> goal;

    if (s.size() != goal.size()) {
        cout << "Not a rotation" << endl;
        return 0;
    }

    string doubled = s + s;

    if (doubled.find(goal) != string::npos)
        cout << "Rotation exists" << endl;
    else
        cout << "Not a rotation" << endl;

    return 0;
}