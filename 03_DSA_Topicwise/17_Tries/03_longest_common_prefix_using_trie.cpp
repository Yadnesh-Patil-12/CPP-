#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Trie {
    struct Node {
        Node* children[26]{};
        int childCount = 0;
        bool isEnd = false;
    };

    Node* root = new Node();

public:
    void insert(const string& word) {
        Node* curr = root;

        for (char c : word) {
            if (c < 'a' || c > 'z')
                return;

            int idx = c - 'a';

            if (!curr->children[idx]) {
                curr->children[idx] = new Node();
                curr->childCount++;
            }

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }

    string longestCommonPrefix() {
        string prefix;
        Node* curr = root;

        while (curr->childCount == 1 && !curr->isEnd) {
            int idx = 0;

            while (idx < 26 && !curr->children[idx])
                idx++;

            if (idx == 26)
                break;

            prefix += char('a' + idx);
            curr = curr->children[idx];
        }

        return prefix;
    }
};

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Empty input\n";
        return 0;
    }

    Trie trie;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        trie.insert(word);
    }

    cout << trie.longestCommonPrefix() << endl;

    return 0;
}