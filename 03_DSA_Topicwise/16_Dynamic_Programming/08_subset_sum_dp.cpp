#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, target;
    cin >> n;

    vector<int> a(n);

    for (int& x : a)
        cin >> x;

    cin >> target;

    if (target < 0) {
        cout << "Invalid target\n";
        return 0;
    }

    for (int x : a) {
        if (x < 0) {
            cout << "Numbers must be non-negative\n";
            return 0;
        }
    }

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int x : a) {
        for (int j = target; j >= x; j--)
            dp[j] = dp[j] || dp[j - x];
    }

    cout << (dp[target] ? "True" : "False") << endl;

    return 0;
}