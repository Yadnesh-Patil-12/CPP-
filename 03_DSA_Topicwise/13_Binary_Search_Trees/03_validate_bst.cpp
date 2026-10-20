#include <iostream>
#include <climits>
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

bool validate(Node* root, long long low, long long high) {
    if (!root) return true;

    if (root->data <= low || root->data >= high)
        return false;

    return validate(root->left, low, root->data) &&
           validate(root->right, root->data, high);
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

    cout << (validate(root, LLONG_MIN, LLONG_MAX)
        ? "Valid BST"
        : "Invalid BST") << endl;

    return 0;
}