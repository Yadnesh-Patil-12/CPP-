#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> result(n, 1);

    long long prefix = 1;

    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= a[i];
    }

    long long suffix = 1;

    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= a[i];
    }

    for (long long x : result)
        cout << x << " ";

    cout << endl;
    return 0;
}