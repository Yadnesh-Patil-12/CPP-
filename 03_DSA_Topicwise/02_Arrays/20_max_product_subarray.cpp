#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long maximum = a[0];
    long long minimum = a[0];
    long long answer = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < 0)
            swap(maximum, minimum);

        maximum = max((long long)a[i], maximum * a[i]);
        minimum = min((long long)a[i], minimum * a[i]);

        answer = max(answer, maximum);
    }

    cout << "Maximum product: " << answer << endl;
    return 0;
}