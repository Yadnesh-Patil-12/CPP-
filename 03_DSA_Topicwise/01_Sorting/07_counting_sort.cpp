#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 0) return 0;

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());

    long long range = (long long)mx - mn + 1;

    // Prevent excessive memory allocation.
    if (range > 1000000) {
        cout << "Range too large for counting sort." << endl;
        return 0;
    }

    vector<int> count((size_t)range, 0);

    for (int x : a)
        count[(size_t)((long long)x - mn)]++;

    for (size_t i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            cout << (long long)i + mn << " ";
            count[i]--;
        }
    }

    cout << endl;
    return 0;
}