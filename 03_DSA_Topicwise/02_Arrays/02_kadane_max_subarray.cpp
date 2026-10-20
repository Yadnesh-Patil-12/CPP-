#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long current = a[0];
    long long best = a[0];

    for (int i = 1; i < n; i++) {
        current = max((long long)a[i], current + a[i]);
        best = max(best, current);
    }

    cout << "Maximum subarray sum: " << best << endl;
    return 0;
}