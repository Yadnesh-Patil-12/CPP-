#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int& x : a)
        cin >> x;

    int prev2 = 0, prev1 = 0;

    for (int x : a) {
        int current = max(prev1, prev2 + x);
        prev2 = prev1;
        prev1 = current;
    }

    cout << prev1 << endl;

    return 0;
}