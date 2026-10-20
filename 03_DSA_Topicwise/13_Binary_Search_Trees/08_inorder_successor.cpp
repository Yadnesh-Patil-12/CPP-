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

Node* findSuccessor(Node* root, int key) {
    Node* successor = nullptr;
    Node* curr = root;

    while (curr) {
        if (key < curr->data) {
            successor = curr;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return successor;
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

    int key;
    cin >> key;

    Node* ans = findSuccessor(root, key);

    if (ans)
        cout << "Inorder successor: " << ans->data << endl;
    else
        cout << "No inorder successor" << endl;

    return 0;
}