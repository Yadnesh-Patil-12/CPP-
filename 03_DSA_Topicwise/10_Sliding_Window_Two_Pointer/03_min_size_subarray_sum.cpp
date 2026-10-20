#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    long long target;

    cin >> n >> target;

    if (n <= 0) {
        cout << "Minimum length: 0" << endl;
        return 0;
    }

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] <= 0) {
            cout << "Elements must be positive." << endl;
            return 0;
        }
    }

    int left = 0;
    long long sum = 0;
    int minLength = INT_MAX;

    for (int right = 0; right < n; right++) {
        sum += a[right];

        while (sum >= target) {
            minLength = min(minLength, right - left + 1);
            sum -= a[left];
            left++;
        }
    }

    cout << "Minimum length: "
         << (minLength == INT_MAX ? 0 : minLength) << endl;

    return 0;
}