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

int diameter(Node* root, int& answer) {
    if (!root) return 0;

    int leftHeight = diameter(root->left, answer);
    int rightHeight = diameter(root->right, answer);

    answer = max(answer, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Node* root = buildTree();

    int answer = 0;
    diameter(root, answer);

    cout << "Diameter in edges: " << answer << endl;

    return 0;
}