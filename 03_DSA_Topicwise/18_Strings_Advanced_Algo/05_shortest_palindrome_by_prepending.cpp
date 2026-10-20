#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> buildLPS(const string& s) {
    vector<int> lps(s.size(), 0);

    int len = 0;

    for (int i = 1; i < (int)s.size();) {
        if (s[i] == s[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }

    return lps;
}

int main() {
    string s;
    cin >> s;

    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    string combined = s + "#" + reversed;

    vector<int> lps = buildLPS(combined);

    int longestPrefix = lps.back();

    string result =
        reversed.substr(0, s.size() - longestPrefix) + s;

    cout << result << endl;

    return 0;
}