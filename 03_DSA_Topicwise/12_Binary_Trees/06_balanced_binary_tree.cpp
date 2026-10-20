#include <iostream>
#include <algorithm>
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

int checkHeight(Node* root) {
    if (!root) return 0;

    int left = checkHeight(root->left);
    if (left == -1) return -1;

    int right = checkHeight(root->right);
    if (right == -1) return -1;

    if (abs(left - right) > 1) return -1;

    return 1 + max(left, right);
}

int main() {
    Node* root = buildTree();

    cout << (checkHeight(root) != -1
        ? "Balanced tree"
        : "Not balanced") << endl;

    return 0;
}