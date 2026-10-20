#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    string s;
    int k;

    getline(cin, s);
    cin >> k;

    if (k <= 0) {
        cout << "Longest length: 0" << endl;
        return 0;
    }

    unordered_map<char, int> freq;

    int left = 0;
    int maxLength = 0;
    int start = 0;

    for (int right = 0; right < (int)s.size(); right++) {
        freq[s[right]]++;

        while ((int)freq.size() > k) {
            freq[s[left]]--;

            if (freq[s[left]] == 0)
                freq.erase(s[left]);

            left++;
        }

        if (right - left + 1 > maxLength) {
            maxLength = right - left + 1;
            start = left;
        }
    }

    cout << "Longest length: " << maxLength << endl;
    cout << "Substring: " << s.substr(start, maxLength) << endl;

    return 0;
}