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

    sort(a.begin(), a.end());

    bool found = false;

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && a[i] == a[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            long long sum = (long long)a[i]
                          + a[left] + a[right];

            if (sum == 0) {
                cout << a[i] << " "
                     << a[left] << " "
                     << a[right] << endl;

                found = true;

                int leftValue = a[left];
                int rightValue = a[right];

                while (left < right &&
                       a[left] == leftValue)
                    left++;

                while (left < right &&
                       a[right] == rightValue)
                    right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    if (!found)
        cout << "No triplets found" << endl;

    return 0;
}