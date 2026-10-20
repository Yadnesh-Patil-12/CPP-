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

bool sameTree(Node* a, Node* b) {
    if (!a || !b) return a == b;

    return a->data == b->data &&
           sameTree(a->left, b->left) &&
           sameTree(a->right, b->right);
}

bool mirror(Node* a, Node* b) {
    if (!a || !b) return a == b;

    return a->data == b->data &&
           mirror(a->left, b->right) &&
           mirror(a->right, b->left);
}

int main() {
    cout << "Enter first tree in preorder (-1 for null): ";
    Node* first = buildTree();

    cout << "Enter second tree in preorder (-1 for null): ";
    Node* second = buildTree();

    cout << "Same tree: "
         << (sameTree(first, second) ? "Yes" : "No") << endl;

    cout << "First tree symmetric: "
         << (mirror(first, first) ? "Yes" : "No") << endl;

    return 0;
}