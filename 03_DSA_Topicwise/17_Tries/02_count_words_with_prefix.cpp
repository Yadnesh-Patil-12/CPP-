#include <iostream>
#include <string>
using namespace std;

class Trie {
    struct Node {
        Node* children[26]{};
        int prefixCount = 0;
        int wordCount = 0;
    };

    Node* root = new Node();

public:
    void insert(const string& word) {
        Node* curr = root;

        for (char c : word) {
            if (c < 'a' || c > 'z')
                return;

            int idx = c - 'a';

            if (!curr->children[idx])
                curr->children[idx] = new Node();

            curr = curr->children[idx];
            curr->prefixCount++;
        }

        curr->wordCount++;
    }

    int countWordsWithPrefix(const string& prefix) {
        Node* curr = root;

        for (char c : prefix) {
            if (c < 'a' || c > 'z')
                return 0;

            int idx = c - 'a';

            if (!curr->children[idx])
                return 0;

            curr = curr->children[idx];
        }

        return curr->prefixCount;
    }
};

int main() {
    Trie trie;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        trie.insert(word);
    }

    string prefix;
    cin >> prefix;

    cout << trie.countWordsWithPrefix(prefix) << endl;

    return 0;
}