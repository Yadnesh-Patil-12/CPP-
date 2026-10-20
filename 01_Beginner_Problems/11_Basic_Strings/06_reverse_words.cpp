#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    stringstream ss(s);
    vector<string> words;
    string word;

    while (ss >> word)
        words.push_back(word);

    reverse(words.begin(), words.end());

    cout << "Reversed words: ";

    for (int i = 0; i < (int)words.size(); i++) {
        if (i > 0) cout << " ";
        cout << words[i];
    }

    cout << endl;
    return 0;
}