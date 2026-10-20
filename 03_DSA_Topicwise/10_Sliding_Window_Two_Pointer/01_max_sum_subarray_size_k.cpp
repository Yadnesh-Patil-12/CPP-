#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n <= 0 || k <= 0 || k > n) {
        cout << "Invalid input" << endl;
        return 0;
    }

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long sum = 0;

    for (int i = 0; i < k; i++)
        sum += a[i];

    long long maxSum = sum;

    for (int i = k; i < n; i++) {
        sum += a[i] - a[i - k];

        if (sum > maxSum)
            maxSum = sum;
    }

    cout << "Maximum sum: " << maxSum << endl;

    return 0;
}