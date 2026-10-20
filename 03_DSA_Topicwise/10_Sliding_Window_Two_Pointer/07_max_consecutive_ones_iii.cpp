#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n < 0 || k < 0) {
        cout << "Invalid input" << endl;
        return 0;
    }

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] != 0 && a[i] != 1) {
            cout << "Array must contain only 0 and 1." << endl;
            return 0;
        }
    }

    int left = 0;
    int zeros = 0;
    int maxLength = 0;

    for (int right = 0; right < n; right++) {
        if (a[right] == 0)
            zeros++;

        while (zeros > k) {
            if (a[left] == 0)
                zeros--;

            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    cout << "Maximum consecutive ones: " << maxLength << endl;

    return 0;
}