#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    string cleaned;

    for (char c : s) {
        if (isalnum(static_cast<unsigned char>(c))) {
            cleaned += static_cast<char>(
                tolower(static_cast<unsigned char>(c))
            );
        }
    }

    string reversed = cleaned;
    reverse(reversed.begin(), reversed.end());

    if (cleaned == reversed)
        cout << "Palindrome string" << endl;
    else
        cout << "Not a palindrome string" << endl;

    return 0;
}