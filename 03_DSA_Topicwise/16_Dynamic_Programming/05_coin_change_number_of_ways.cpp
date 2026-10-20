#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, amount;
    cin >> n;

    vector<int> coins(n);

    for (int& x : coins)
        cin >> x;

    cin >> amount;

    if (amount < 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int x : coins) {
        if (x <= 0) {
            cout << "Coins must be positive\n";
            return 0;
        }
    }

    vector<long long> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int j = coin; j <= amount; j++)
            dp[j] += dp[j - coin];
    }

    cout << dp[amount] << endl;

    return 0;
}