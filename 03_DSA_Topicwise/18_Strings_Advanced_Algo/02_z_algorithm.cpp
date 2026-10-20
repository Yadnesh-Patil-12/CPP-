#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> zFunction(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);

    int left = 0, right = 0;

    for (int i = 1; i < n; i++) {
        if (i <= right)
            z[i] = min(right - i + 1, z[i - left]);

        while (i + z[i] < n &&
               s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }

    return z;
}

int main() {
    string s;
    cin >> s;

    vector<int> z = zFunction(s);

    for (int x : z)
        cout << x << " ";

    cout << endl;

    return 0;
}