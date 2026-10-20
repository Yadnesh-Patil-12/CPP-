#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    string compressed;

    for (int i = 0; i < (int)s.size();) {
        int j = i;

        while (j < (int)s.size() && s[j] == s[i])
            j++;

        compressed += s[i];
        compressed += to_string(j - i);

        i = j;
    }

    cout << "Compressed string: " << compressed << endl;
    return 0;
}