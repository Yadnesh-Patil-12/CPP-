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

int countLeaves(Node* root) {
    if (!root) return 0;

    if (!root->left && !root->right)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

long long sumNodes(Node* root) {
    if (!root) return 0;

    return root->data +
           sumNodes(root->left) +
           sumNodes(root->right);
}

int main() {
    Node* root = buildTree();

    cout << "Leaf nodes: " << countLeaves(root) << endl;
    cout << "Sum of nodes: " << sumNodes(root) << endl;

    return 0;
}