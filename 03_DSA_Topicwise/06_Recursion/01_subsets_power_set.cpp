#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    vector<int> lastSeen(256, -1);

    int left = 0;
    int maxLength = 0;
    int start = 0;

    for (int right = 0; right < (int)s.size(); right++) {
        unsigned char c = s[right];

        if (lastSeen[c] >= left)
            left = lastSeen[c] + 1;

        lastSeen[c] = right;

        if (right - left + 1 > maxLength) {
            maxLength = right - left + 1;
            start = left;
        }
    }

    cout << "Length: " << maxLength << endl;
    cout << "Substring: " << s.substr(start, maxLength) << endl;

    return 0;
}