#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int target;
    cin >> target;

    int left = 0, right = n;

    // Lower bound: first element >= target
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (a[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    cout << "Lower bound index: " << left << endl;

    left = 0;
    right = n;

    // Upper bound: first element > target
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (a[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }

    cout << "Upper bound index: " << left << endl;

    return 0;
}