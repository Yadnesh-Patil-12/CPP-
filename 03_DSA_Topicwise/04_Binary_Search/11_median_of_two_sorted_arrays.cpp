#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    if (n == 0 && m == 0) {
        cout << "Both arrays are empty." << endl;
        return 0;
    }

    if (n > m) {
        swap(a, b);
        swap(n, m);
    }

    int left = 0, right = n;

    while (left <= right) {
        int i = left + (right - left) / 2;
        int j = (n + m + 1) / 2 - i;

        int leftA = (i == 0) ? INT_MIN : a[i - 1];
        int rightA = (i == n) ? INT_MAX : a[i];

        int leftB = (j == 0) ? INT_MIN : b[j - 1];
        int rightB = (j == m) ? INT_MAX : b[j];

        if (leftA <= rightB && leftB <= rightA) {
            long long maxLeft = max(leftA, leftB);

            if ((n + m) % 2 == 1) {
                cout << "Median: " << maxLeft << endl;
            } else {
                long long minRight = min(rightA, rightB);
                cout << "Median: "
                     << (maxLeft + minRight) / 2.0 << endl;
            }

            return 0;
        }

        if (leftA > rightB)
            right = i - 1;
        else
            left = i + 1;
    }

    cout << "Input arrays must be sorted." << endl;
    return 0;
}