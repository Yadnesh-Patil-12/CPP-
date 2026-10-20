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

    int farthest = 0;

    for (int i = 0; i < n; i++) {
        if (i > farthest) {
            cout << "Cannot reach the end" << endl;
            return 0;
        }

        farthest = max(farthest, i + a[i]);

        if (farthest >= n - 1) {
            cout << "Can reach the end" << endl;
            return 0;
        }
    }

    cout << (n == 1 ? "Can reach the end" :
                         "Cannot reach the end") << endl;

    return 0;
}