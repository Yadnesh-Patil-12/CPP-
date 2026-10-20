#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int& x : a)
        cin >> x;

    for (int x : a) {
        if (x < 0) {
            cout << "Numbers must be non-negative\n";
            return 0;
        }
    }

    int sum = accumulate(a.begin(), a.end(), 0);

    if (sum % 2 != 0) {
        cout << "False\n";
        return 0;
    }

    int target = sum / 2;
    vector<bool> dp(target + 1, false);

    dp[0] = true;

    for (int x : a) {
        for (int j = target; j >= x; j--)
            dp[j] = dp[j] || dp[j - x];
    }

    cout << (dp[target] ? "True" : "False") << endl;

    return 0;
}