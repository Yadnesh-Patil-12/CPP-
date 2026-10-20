#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right])
            return false;

        left++;
        right--;
    }

    return true;
}

void partitionString(const string& s, int start,
                     vector<string>& current) {
    if (start == (int)s.size()) {
        for (int i = 0; i < (int)current.size(); i++) {
            if (i > 0) cout << " | ";
            cout << current[i];
        }

        cout << endl;
        return;
    }

    for (int end = start; end < (int)s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1));

            partitionString(s, end + 1, current);

            current.pop_back();
        }
    }
}

int main() {
    string s;
    cin >> s;

    vector<string> current;

    partitionString(s, 0, current);

    return 0;
}