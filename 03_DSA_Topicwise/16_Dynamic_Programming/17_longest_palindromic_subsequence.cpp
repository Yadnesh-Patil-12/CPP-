#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    vector<vector<int>> dp(
        n, vector<int>(n, 0)
    );

    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;

        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];
            else
                dp[i][j] = max(
                    dp[i + 1][j],
                    dp[i][j - 1]
                );
        }
    }

    cout << (n == 0 ? 0 : dp[0][n - 1]) << endl;

    return 0;
}