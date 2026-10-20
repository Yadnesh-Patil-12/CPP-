#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> piles(n);
    for (int i = 0; i < n; i++)
        cin >> piles[i];

    long long h;
    cin >> h;

    if (n <= 0 || h < n) {
        cout << "Impossible" << endl;
        return 0;
    }

    int left = 1;
    int right = *max_element(piles.begin(), piles.end());

    while (left < right) {
        int mid = left + (right - left) / 2;
        long long hours = 0;

        for (int pile : piles) {
            hours += pile / mid + (pile % mid != 0);

            if (hours > h) break;
        }

        if (hours <= h)
            right = mid;
        else
            left = mid + 1;
    }

    cout << "Minimum eating speed: " << left << endl;
    return 0;
}