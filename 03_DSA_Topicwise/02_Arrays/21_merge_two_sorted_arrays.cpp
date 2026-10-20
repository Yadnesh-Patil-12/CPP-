#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> result;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j])
            result.push_back(a[i++]);
        else
            result.push_back(b[j++]);
    }

    while (i < n) result.push_back(a[i++]);
    while (j < m) result.push_back(b[j++]);

    for (int x : result)
        cout << x << " ";

    cout << endl;
    return 0;
}