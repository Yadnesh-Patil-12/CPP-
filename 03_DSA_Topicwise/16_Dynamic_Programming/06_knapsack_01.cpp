#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<int> weight(n), value(n);

    for (int& x : weight)
        cin >> x;

    for (int& x : value)
        cin >> x;

    if (capacity < 0) {
        cout << "Invalid capacity\n";
        return 0;
    }

    vector<long long> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++) {
        if (weight[i] <= 0) {
            cout << "Weights must be positive\n";
            return 0;
        }

        for (int w = capacity; w >= weight[i]; w--) {
            dp[w] = max(
                dp[w],
                dp[w - weight[i]] + value[i]
            );
        }
    }

    cout << dp[capacity] << endl;

    return 0;
}