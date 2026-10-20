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

int height(Node* root) {
    if (!root) return 0;

    return 1 + max(height(root->left), height(root->right));
}

int countNodes(Node* root) {
    if (!root) return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = buildTree();

    cout << "Height: " << height(root) << endl;
    cout << "Node count: " << countNodes(root) << endl;

    return 0;
}