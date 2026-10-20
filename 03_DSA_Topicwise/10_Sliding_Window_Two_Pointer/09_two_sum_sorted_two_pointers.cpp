#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long target;

    cin >> n >> target;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int left = 0;
    int right = n - 1;

    while (left < right) {
        long long sum = (long long)a[left] + a[right];

        if (sum == target) {
            cout << "Pair found: "
                 << a[left] << " " << a[right] << endl;

            cout << "Indices (0-based): "
                 << left << " " << right << endl;

            return 0;
        }

        if (sum < target)
            left++;
        else
            right--;
    }

    cout << "No pair found" << endl;

    return 0;
}