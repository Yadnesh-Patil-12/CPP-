#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int left = 0, right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (a[mid] > a[right])
            left = mid + 1;
        else
            right = mid;
    }

    cout << "Minimum element: " << a[left] << endl;
    return 0;
}