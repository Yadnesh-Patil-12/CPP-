#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    set<int> s = {30, 10, 20, 10, 30};

    cout << "Ordered Set: ";
    for (int x : s) {
        cout << x << " ";
    }

    unordered_set<int> us = {30, 10, 20, 10, 30};

    cout << "\nUnordered Set: ";
    for (int x : us) {
        cout << x << " ";
    }

    cout << "\nContains 20: "
         << (s.count(20) ? "Yes" : "No") << endl;

    return 0;
}