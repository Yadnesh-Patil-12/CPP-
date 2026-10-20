#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    unordered_map<char, int> frequency;

    for (char c : s) {
        if (c != ' ')
            frequency[c]++;
    }

    for (auto p : frequency)
        cout << p.first << " : " << p.second << endl;

    return 0;
}