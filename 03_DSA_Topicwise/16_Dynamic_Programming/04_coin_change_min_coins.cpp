#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, amount;
    cin >> n;

    vector<int> coins(n);

    for (int& x : coins)
        cin >> x;

    cin >> amount;

    if (amount < 0) {
        cout << -1 << endl;
        return 0;
    }

    for (int x : coins) {
        if (x <= 0) {
            cout << "Coins must be positive\n";
            return 0;
        }
    }

    const int INF = 1e9;
    vector<int> dp(amount + 1, INF);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INF)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    cout << (dp[amount] == INF ? -1 : dp[amount]) << endl;

    return 0;
}