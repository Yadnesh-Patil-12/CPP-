#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int x) {
    if (!root) return new Node(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

bool search(Node* root, int x) {
    while (root) {
        if (root->data == x) return true;

        root = (x < root->data) ? root->left : root->right;
    }

    return false;
}

Node* lca(Node* root, int a, int b) {
    while (root) {
        if (a < root->data && b < root->data)
            root = root->left;
        else if (a > root->data && b > root->data)
            root = root->right;
        else
            return root;
    }

    return nullptr;
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int a, b;
    cin >> a >> b;

    if (!search(root, a) || !search(root, b)) {
        cout << "Node not found" << endl;
        return 0;
    }

    Node* ans = lca(root, a, b);

    if (ans)
        cout << "LCA: " << ans->data << endl;

    return 0;
}