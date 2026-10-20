#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> seen;
    bool duplicate = false;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (seen.count(x))
            duplicate = true;

        seen.insert(x);
    }

    if (duplicate)
        cout << "Contains duplicate" << endl;
    else
        cout << "No duplicates" << endl;

    return 0;
}