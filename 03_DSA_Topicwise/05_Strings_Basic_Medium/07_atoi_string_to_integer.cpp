#include <iostream>
#include <string>
#include <climits>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int i = 0;
    int n = s.size();
    int sign = 1;
    long long result = 0;

    while (i < n && isspace(static_cast<unsigned char>(s[i])))
        i++;

    if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-')
            sign = -1;
        i++;
    }

    while (i < n && isdigit(static_cast<unsigned char>(s[i]))) {
        result = result * 10 + (s[i] - '0');

        long long value = result * sign;

        if (value > INT_MAX) {
            cout << INT_MAX << endl;
            return 0;
        }

        if (value < INT_MIN) {
            cout << INT_MIN << endl;
            return 0;
        }

        i++;
    }

    cout << "Integer: " << result * sign << endl;
    return 0;
}