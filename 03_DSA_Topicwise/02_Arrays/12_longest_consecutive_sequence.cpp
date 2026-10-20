#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    unordered_set<int> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }

    int longest = 0;

    for (int x : s) {
        // Avoid overflow when checking x - 1.
        if (x != -2147483648 &&
            s.find(x - 1) != s.end()) {
            continue;
        }

        int length = 1;
        int current = x;

        while (current != 2147483647 &&
               s.find(current + 1) != s.end()) {
            current++;
            length++;
        }

        if (length > longest)
            longest = length;
    }

    cout << "Longest consecutive sequence: "
         << longest << endl;

    return 0;
}