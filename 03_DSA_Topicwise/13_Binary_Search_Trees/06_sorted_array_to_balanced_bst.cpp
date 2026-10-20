#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* buildBST(const vector<int>& a, int left, int right) {
    if (left > right) return nullptr;

    int mid = left + (right - left) / 2;

    Node* root = new Node(a[mid]);

    root->left = buildBST(a, left, mid - 1);
    root->right = buildBST(a, mid + 1, right);

    return root;
}

void preorder(Node* root) {
    if (!root) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1]) {
            cout << "Array must be strictly increasing." << endl;
            return 0;
        }
    }

    Node* root = buildBST(a, 0, n - 1);

    cout << "Balanced BST preorder: ";
    preorder(root);

    cout << endl;
    return 0;
}