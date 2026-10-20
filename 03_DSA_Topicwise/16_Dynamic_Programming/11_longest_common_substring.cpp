#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();
    int answer = 0;

    vector<vector<int>> dp(
        n + 1, vector<int>(m + 1, 0)
    );

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                answer = max(answer, dp[i][j]);
            }
        }
    }

    cout << answer << endl;

    return 0;
}