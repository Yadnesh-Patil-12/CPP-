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

Node* lca(Node* root, int p, int q) {
    if (!root || root->data == p || root->data == q)
        return root;

    Node* left = lca(root->left, p, q);
    Node* right = lca(root->right, p, q);

    if (left && right) return root;

    return left ? left : right;
}

bool exists(Node* root, int x) {
    if (!root) return false;

    if (root->data == x) return true;

    return exists(root->left, x) || exists(root->right, x);
}

int main() {
    Node* root = buildTree();

    int p, q;
    cin >> p >> q;

    if (!exists(root, p) || !exists(root, q)) {
        cout << "Node not found" << endl;
        return 0;
    }

    Node* ans = lca(root, p, q);

    if (ans)
        cout << "LCA: " << ans->data << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}