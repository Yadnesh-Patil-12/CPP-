#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string a, b;

    cout << "Enter first string: ";
    getline(cin, a);

    cout << "Enter second string: ";
    getline(cin, b);

    string x, y;

    for (char c : a) {
        if (!isspace(static_cast<unsigned char>(c)))
            x += static_cast<char>(
                tolower(static_cast<unsigned char>(c))
            );
    }

    for (char c : b) {
        if (!isspace(static_cast<unsigned char>(c)))
            y += static_cast<char>(
                tolower(static_cast<unsigned char>(c))
            );
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    if (x == y)
        cout << "Valid anagrams" << endl;
    else
        cout << "Not anagrams" << endl;

    return 0;
}