#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) return 0;

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int minimumPrice = prices[0];
    long long maxProfit = 0;

    for (int i = 1; i < n; i++) {
        maxProfit = max(maxProfit,
                        (long long)prices[i] - minimumPrice);

        minimumPrice = min(minimumPrice, prices[i]);
    }

    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}