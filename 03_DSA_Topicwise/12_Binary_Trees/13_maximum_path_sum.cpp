#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* buildTree() {
    int x;
    cin >> x;

    if (x == -1) return nullptr;

    Node* root = new Node(x);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

long long maxPath(Node* root, long long& answer) {
    if (!root) return 0;

    long long left = max(0LL, maxPath(root->left, answer));
    long long right = max(0LL, maxPath(root->right, answer));

    answer = max(answer, (long long)root->data + left + right);

    return root->data + max(left, right);
}

int main() {
    Node* root = buildTree();

    if (!root) {
        cout << "Tree is empty" << endl;
        return 0;
    }

    long long answer = LLONG_MIN;
    maxPath(root, answer);

    cout << "Maximum path sum: " << answer << endl;

    return 0;
}