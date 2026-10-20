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

    if (next_permutation(a.begin(), a.end())) {
        cout << "Next permutation: ";
    } else {
        cout << "No next permutation; smallest permutation: ";
    }

    for (int x : a)
        cout << x << " ";

    cout << endl;
    return 0;
}