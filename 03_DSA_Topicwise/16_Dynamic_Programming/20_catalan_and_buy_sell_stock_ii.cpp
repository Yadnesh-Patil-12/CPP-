#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long catalan(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++)
            dp[i] += dp[j] * dp[i - 1 - j];
    }

    return dp[n];
}

long long maxProfit(vector<int>& prices) {
    long long profit = 0;

    for (int i = 1; i < (int)prices.size(); i++) {
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    }

    return profit;
}

int main() {
    string choice;
    cin >> choice;

    if (choice == "catalan") {
        int n;
        cin >> n;

        if (n < 0 || n > 35) {
            cout << "Enter n between 0 and 35\n";
            return 0;
        }

        cout << catalan(n) << endl;
    }
    else if (choice == "stock") {
        int n;
        cin >> n;

        vector<int> prices(n);

        for (int& x : prices)
            cin >> x;

        cout << maxProfit(prices) << endl;
    }
    else {
        cout << "Choose catalan or stock\n";
    }

    return 0;
}