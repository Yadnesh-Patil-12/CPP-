#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 0 || n > 20) {
        cout << "Enter n between 0 and 20." << endl;
        return 0;
    }

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int total = 1 << n;

    for (int mask = 0; mask < total; mask++) {
        cout << "{ ";

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
                cout << a[i] << " ";
        }

        cout << "}" << endl;
    }

    return 0;
}