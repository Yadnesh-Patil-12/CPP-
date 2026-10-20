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

Node* invert(Node* root) {
    if (!root) return nullptr;

    swap(root->left, root->right);

    invert(root->left);
    invert(root->right);

    return root;
}

void preorder(Node* root) {
    if (!root) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = buildTree();

    invert(root);

    cout << "Inverted tree preorder: ";
    preorder(root);

    cout << endl;
    return 0;
}