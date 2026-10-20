#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& s, int left, int right) {
    if (left >= right) return true;

    if (s[left] != s[right])
        return false;

    return isPalindrome(s, left + 1, right - 1);
}

int main() {
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    if (isPalindrome(s, 0, static_cast<int>(s.size()) - 1))
        cout << "Palindrome string" << endl;
    else
        cout << "Not a palindrome string" << endl;

    return 0;
}