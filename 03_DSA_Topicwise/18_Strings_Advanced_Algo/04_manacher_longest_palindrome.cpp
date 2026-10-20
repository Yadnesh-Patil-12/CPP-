#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
    string t = "^";

    for (char c : s) {
        t += "#";
        t += c;
    }

    t += "#$";

    int n = t.size();
    vector<int> p(n, 0);

    int center = 0, right = 0;
    int maxLen = 0, centerIndex = 0;

    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;

        if (i < right)
            p[i] = min(right - i, p[mirror]);

        while (t[i + 1 + p[i]] ==
               t[i - 1 - p[i]]) {
            p[i]++;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }

        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;

    return s.substr(start, maxLen);
}

int main() {
    string s;
    cin >> s;

    cout << longestPalindrome(s) << endl;

    return 0;
}