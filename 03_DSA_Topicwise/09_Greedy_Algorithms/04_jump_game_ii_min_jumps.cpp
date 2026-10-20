#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) return 0;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] < 0) {
            cout << "Jump lengths cannot be negative." << endl;
            return 0;
        }
    }

    if (n == 1) {
        cout << "Minimum jumps: 0" << endl;
        return 0;
    }

    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < n - 1; i++) {
        if (i > farthest) break;

        farthest = max(farthest, i + a[i]);

        if (i == currentEnd) {
            if (farthest == currentEnd) {
                cout << "End is unreachable" << endl;
                return 0;
            }

            jumps++;
            currentEnd = farthest;

            if (currentEnd >= n - 1) break;
        }
    }

    cout << "Minimum jumps: " << jumps << endl;
    return 0;
}