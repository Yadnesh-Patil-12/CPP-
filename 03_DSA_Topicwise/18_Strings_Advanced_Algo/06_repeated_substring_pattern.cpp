#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    if (n < 2) {
        cout << "False\n";
        return 0;
    }

    vector<int> lps(n, 0);

    int len = 0;

    for (int i = 1; i < n;) {
        if (s[i] == s[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }

    int longestPrefix = lps[n - 1];
    int patternLength = n - longestPrefix;

    if (longestPrefix > 0 && n % patternLength == 0)
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}