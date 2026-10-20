#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main() {
    string s, t;

    getline(cin, s);
    getline(cin, t);

    if (t.empty() || s.size() < t.size()) {
        cout << "Minimum window: " << endl;
        return 0;
    }

    vector<int> need(256, 0);

    for (unsigned char c : t)
        need[c]++;

    int left = 0;
    int missing = t.size();

    int start = 0;
    int minLength = INT_MAX;

    for (int right = 0; right < (int)s.size(); right++) {
        unsigned char c = s[right];

        if (need[c] > 0)
            missing--;

        need[c]--;

        while (missing == 0) {
            if (right - left + 1 < minLength) {
                minLength = right - left + 1;
                start = left;
            }

            unsigned char lc = s[left];
            need[lc]++;

            if (need[lc] > 0)
                missing++;

            left++;
        }
    }

    if (minLength == INT_MAX)
        cout << "No valid window found" << endl;
    else
        cout << "Minimum window: "
             << s.substr(start, minLength) << endl;

    return 0;
}