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

    long long target;
    cin >> target;

    sort(a.begin(), a.end());

    bool found = false;

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && a[i] == a[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && a[j] == a[j - 1])
                continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right) {
                long long sum = (long long)a[i] + a[j]
                              + a[left] + a[right];

                if (sum == target) {
                    cout << a[i] << " " << a[j] << " "
                         << a[left] << " " << a[right]
                         << endl;

                    found = true;

                    int lv = a[left];
                    int rv = a[right];

                    while (left < right && a[left] == lv)
                        left++;

                    while (left < right && a[right] == rv)
                        right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    if (!found)
        cout << "No quadruplets found" << endl;

    return 0;
}