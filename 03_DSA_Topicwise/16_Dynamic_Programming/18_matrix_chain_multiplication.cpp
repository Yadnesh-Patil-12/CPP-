#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 2) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> p(n);

    for (int& x : p)
        cin >> x;

    for (int x : p) {
        if (x <= 0) {
            cout << "Dimensions must be positive\n";
            return 0;
        }
    }

    int matrices = n - 1;

    vector<vector<long long>> dp(
        matrices + 1,
        vector<long long>(matrices + 1, 0)
    );

    for (int len = 2; len <= matrices; len++) {
        for (int i = 1; i + len - 1 <= matrices; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {
                long long cost =
                    dp[i][k] + dp[k + 1][j] +
                    1LL * p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[1][matrices] << endl;

    return 0;
}