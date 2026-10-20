#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size\n";
        return 0;
    }

    vector<long long> a(n);

    for (auto& x : a)
        cin >> x;

    long long maxEnding = a[0];
    long long minEnding = a[0];
    long long answer = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < 0)
            swap(maxEnding, minEnding);

        maxEnding = max(a[i], maxEnding * a[i]);
        minEnding = min(a[i], minEnding * a[i]);

        answer = max(answer, maxEnding);
    }

    cout << answer << endl;

    return 0;
}