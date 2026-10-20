#include <iostream>
#include <string>
using namespace std;

int romanValue(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int main() {
    string s;
    cin >> s;

    int result = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        int current = romanValue(s[i]);

        if (current == 0) {
            cout << "Invalid Roman numeral character" << endl;
            return 0;
        }

        if (i + 1 < (int)s.size()
            && current < romanValue(s[i + 1])) {
            result -= current;
        } else {
            result += current;
        }
    }

    cout << "Integer value: " << result << endl;
    return 0;
}