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
    if (!root) return false;

    if (root->data == x) return true;

    if (x < root->data)
        return search(root->left, x);

    return search(root->right, x);
}

void inorder(Node* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    int target;
    cin >> target;

    inorder(root);

    cout << "\nSearch result: "
         << (search(root, target) ? "Found" : "Not found")
         << endl;

    return 0;
}