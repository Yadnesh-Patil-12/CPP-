#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) return 0;

    vector<int> ratings(n);
    vector<int> candies(n, 1);

    for (int i = 0; i < n; i++)
        cin >> ratings[i];

    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1])
            candies[i] = max(candies[i], candies[i + 1] + 1);
    }

    long long total = 0;

    for (int x : candies)
        total += x;

    cout << "Candies per child: ";

    for (int x : candies)
        cout << x << " ";

    cout << "\nMinimum candies required: " << total << endl;

    return 0;
}