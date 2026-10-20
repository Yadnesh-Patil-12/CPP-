#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    if (m <= 0 || n <= 0) {
        cout << "Invalid grid\n";
        return 0;
    }

    vector<vector<int>> grid(
        m, vector<int>(n)
    );

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    vector<vector<long long>> dp(
        m, vector<long long>(n, 0)
    );

    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (int j = 1; j < n; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(
                dp[i - 1][j],
                dp[i][j - 1]
            );
        }
    }

    cout << dp[m - 1][n - 1] << endl;

    return 0;
}