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

    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == target) {
            cout << "Found at index: " << mid << endl;
            return 0;
        }

        if (a[left] <= a[mid]) {
            if (a[left] <= target && target < a[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else {
            if (a[mid] < target && target <= a[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    cout << "Not found" << endl;
    return 0;
}