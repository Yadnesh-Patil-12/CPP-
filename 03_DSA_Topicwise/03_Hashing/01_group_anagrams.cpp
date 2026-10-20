#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];

    unordered_map<string, vector<string>> groups;

    for (string word : words) {
        string key = word;
        sort(key.begin(), key.end());
        groups[key].push_back(word);
    }

    for (const auto& group : groups) {
        for (const string& word : group.second)
            cout << word << " ";
        cout << endl;
    }

    return 0;
}