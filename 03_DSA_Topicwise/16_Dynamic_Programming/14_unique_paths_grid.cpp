#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    if (m <= 0 || n <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<long long>> dp(
        m, vector<long long>(n, 1)
    );

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }

    cout << dp[m - 1][n - 1] << endl;

    return 0;
}