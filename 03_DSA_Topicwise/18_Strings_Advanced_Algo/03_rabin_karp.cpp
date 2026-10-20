#include <iostream>
#include <string>
using namespace std;

void rabinKarp(const string& text,
               const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    if (m == 0 || m > n) {
        cout << "Pattern not found\n";
        return;
    }

    const long long BASE = 256;
    const long long MOD = 1000000007;

    long long patternHash = 0;
    long long windowHash = 0;
    long long power = 1;

    for (int i = 0; i < m - 1; i++)
        power = (power * BASE) % MOD;

    for (int i = 0; i < m; i++) {
        patternHash =
            (patternHash * BASE + pattern[i]) % MOD;

        windowHash =
            (windowHash * BASE + text[i]) % MOD;
    }

    bool found = false;

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == windowHash &&
            text.compare(i, m, pattern) == 0) {
            cout << "Pattern found at index "
                 << i << endl;
            found = true;
        }

        if (i < n - m) {
            windowHash =
                (windowHash - text[i] * power % MOD + MOD)
                % MOD;

            windowHash =
                (windowHash * BASE + text[i + m]) % MOD;
        }
    }

    if (!found)
        cout << "Pattern not found\n";
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    rabinKarp(text, pattern);

    return 0;
}