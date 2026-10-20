#include <iostream>
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

bool hasPathSum(Node* root, long long target) {
    if (!root) return false;

    target -= root->data;

    if (!root->left && !root->right)
        return target == 0;

    return hasPathSum(root->left, target) ||
           hasPathSum(root->right, target);
}

int main() {
    Node* root = buildTree();

    long long target;
    cin >> target;

    cout << (hasPathSum(root, target)
        ? "Path sum exists"
        : "Path sum does not exist") << endl;

    return 0;
}