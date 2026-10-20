#include <iostream>
#include <string>
using namespace std;

class WordDictionary {
    struct Node {
        Node* children[26]{};
        bool isEnd = false;
    };

    Node* root = new Node();

    bool searchHelper(const string& word, int pos, Node* node) {
        if (pos == (int)word.size())
            return node->isEnd;

        char c = word[pos];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] &&
                    searchHelper(word, pos + 1, node->children[i]))
                    return true;
            }

            return false;
        }

        if (c < 'a' || c > 'z')
            return false;

        int idx = c - 'a';

        if (!node->children[idx])
            return false;

        return searchHelper(word, pos + 1, node->children[idx]);
    }

public:
    void addWord(const string& word) {
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
        return searchHelper(word, 0, root);
    }
};

int main() {
    WordDictionary dictionary;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        dictionary.addWord(word);
    }

    string query;
    cin >> query;

    cout << (dictionary.search(query)
        ? "Found"
        : "Not found") << endl;

    return 0;
}