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

    int first = -1, last = -1;
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] >= target) {
            if (a[mid] == target)
                first = mid;

            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    left = 0;
    right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] <= target) {
            if (a[mid] == target)
                last = mid;

            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << "First occurrence: " << first << endl;
    cout << "Last occurrence: " << last << endl;

    return 0;
}