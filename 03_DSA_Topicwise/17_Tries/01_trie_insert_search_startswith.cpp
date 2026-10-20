#include <iostream>
#include <string>
using namespace std;

class Trie {
    struct Node {
        Node* children[26]{};
        bool isEnd = false;
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* curr = root;

        for (char c : word) {
            if (c < 'a' || c > 'z')
                return;

            int idx = c - 'a';

            if (!curr->children[idx])
                curr->children[idx] = new Node();

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }

    bool search(const string& word) {
        Node* curr = root;

        for (char c : word) {
            if (c < 'a' || c > 'z')
                return false;

            int idx = c - 'a';

            if (!curr->children[idx])
                return false;

            curr = curr->children[idx];
        }

        return curr->isEnd;
    }

    bool startsWith(const string& prefix) {
        Node* curr = root;

        for (char c : prefix) {
            if (c < 'a' || c > 'z')
                return false;

            int idx = c - 'a';

            if (!curr->children[idx])
                return false;

            curr = curr->children[idx];
        }

        return true;
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

    string word, prefix;
    cin >> word >> prefix;

    cout << (trie.search(word) ? "Found" : "Not found")
         << endl;

    cout << (trie.startsWith(prefix)
        ? "Prefix exists"
        : "Prefix does not exist") << endl;

    return 0;
}