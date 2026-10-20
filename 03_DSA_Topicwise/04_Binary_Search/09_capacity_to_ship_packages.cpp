#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) return 0;

    vector<int> weights(n);
    long long left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        cin >> weights[i];

        if (weights[i] <= 0) {
            cout << "Weights must be positive." << endl;
            return 0;
        }

        left = max(left, (long long)weights[i]);
        right += weights[i];
    }

    int days;
    cin >> days;

    if (days <= 0 || days > n) {
        cout << "Invalid number of days." << endl;
        return 0;
    }

    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long currentWeight = 0;
        int requiredDays = 1;

        for (int w : weights) {
            if (currentWeight + w > mid) {
                requiredDays++;
                currentWeight = 0;
            }

            currentWeight += w;
        }

        if (requiredDays <= days)
            right = mid;
        else
            left = mid + 1;
    }

    cout << "Minimum ship capacity: " << left << endl;
    return 0;
}