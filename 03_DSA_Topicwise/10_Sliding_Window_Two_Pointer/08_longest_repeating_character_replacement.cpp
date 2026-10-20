#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    int k;

    getline(cin, s);
    cin >> k;

    if (k < 0) {
        cout << "Invalid k" << endl;
        return 0;
    }

    vector<int> freq(256, 0);

    int left = 0;
    int maxFreq = 0;
    int maxLength = 0;

    for (int right = 0; right < (int)s.size(); right++) {
        unsigned char c = s[right];

        freq[c]++;
        maxFreq = max(maxFreq, freq[c]);

        while ((right - left + 1) - maxFreq > k) {
            freq[(unsigned char)s[left]]--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    cout << "Longest repeating character length: "
         << maxLength << endl;

    return 0;
}