#include <iostream>
#include <vector>
using namespace std;

class Trie {
    struct Node {
        Node* child[2]{};
    };

    Node* root = new Node();

public:
    void insert(int x) {
        Node* curr = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;

            if (!curr->child[bit])
                curr->child[bit] = new Node();

            curr = curr->child[bit];
        }
    }

    int maxXor(int x) {
        Node* curr = root;
        int result = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int opposite = 1 - bit;

            if (curr->child[opposite]) {
                result |= (1U << i);
                curr = curr->child[opposite];
            } else {
                curr = curr->child[bit];
            }
        }

        return result;
    }
};

int main() {
    int n;
    cin >> n;

    if (n < 2) {
        cout << "At least two numbers required\n";
        return 0;
    }

    vector<int> a(n);

    for (int& x : a) {
        cin >> x;

        if (x < 0) {
            cout << "Enter non-negative numbers\n";
            return 0;
        }
    }

    Trie trie;

    for (int x : a)
        trie.insert(x);

    int answer = 0;

    for (int x : a)
        answer = max(answer, trie.maxXor(x));

    cout << answer << endl;

    return 0;
}