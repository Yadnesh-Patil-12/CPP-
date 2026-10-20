#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> leaders;
    int maximum = a[n - 1];

    leaders.push_back(maximum);

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] >= maximum) {
            maximum = a[i];
            leaders.push_back(a[i]);
        }
    }

    reverse(leaders.begin(), leaders.end());

    for (int x : leaders)
        cout << x << " ";

    cout << endl;
    return 0;
}