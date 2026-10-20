#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int words = 0;
    bool inWord = false;

    for (char &c : s) {
        unsigned char ch = static_cast<unsigned char>(c);

        if (islower(ch))
            c = static_cast<char>(toupper(ch));
        else if (isupper(ch))
            c = static_cast<char>(tolower(ch));

        if (isspace(static_cast<unsigned char>(c))) {
            inWord = false;
        } else if (!inWord) {
            words++;
            inWord = true;
        }
    }

    cout << "Toggled string: " << s << endl;
    cout << "Word count: " << words << endl;

    return 0;
}