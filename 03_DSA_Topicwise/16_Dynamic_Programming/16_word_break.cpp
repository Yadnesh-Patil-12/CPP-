#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    unordered_set<string> dict;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        dict.insert(word);
    }

    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= (int)s.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] &&
                dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }

    cout << (dp[s.size()] ? "True" : "False") << endl;

    return 0;
}