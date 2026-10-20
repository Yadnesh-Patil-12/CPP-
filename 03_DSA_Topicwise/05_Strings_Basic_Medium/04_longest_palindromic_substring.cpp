#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int start = 0, maxLength = 0;

    for (int center = 0; center < (int)s.size(); center++) {
        int left = center, right = center;

        while (left >= 0 && right < (int)s.size()
               && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }

            left--;
            right++;
        }

        left = center;
        right = center + 1;

        while (left >= 0 && right < (int)s.size()
               && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }

            left--;
            right++;
        }
    }

    cout << "Longest palindrome: "
         << s.substr(start, maxLength) << endl;

    return 0;
}